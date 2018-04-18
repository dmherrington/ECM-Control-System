////////////////////////////////////////////////////////////////////////////////
// File			: s2410.c
// Function		: API for Sensoray 2410
// Target		: OS-independent
// Author		: Jim Lamberson
// Created		: 2008/07/10
// Copyright	: Copyright (C) 2010 Sensoray
////////////////////////////////////////////////////////////////////////////////


#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define S24XX_EXPORTS

#include "osi_wrapper.h"
#include "s24xx.h"
#include "session.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  UTILITY FUNCTIONS  //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
// API: Program brightness of DIO status LEDs.
// Imports:
//	intensity - brightness in range 0 (always off) to 16 (max brightness).
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_SetLedBrightness( HSESSION sess, S24XXERR *err, uint intensity )
{
	char cmd[20];		// command buffer
	
	if ( intensity > 16 )
		intensity = 16;

	sprintf( cmd, "led %d\r\n", intensity );					// Build command message -- 2410 intensity range: 0 to 16
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );		// Execute command.
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Command helper - Issue shell command that sends 48 bit flags in 3 words, wait for and process reply.
// Imports:
//	opcmd	- command line prefix (i.e., shell command that precedes flag words).
//	flags[]	- logic 1's specify affected channels (or edge polarity), words ordered LSW first.
// Returns TRUE if command successfully executed.

static BOOL ExecCmdWriteFlags( HSESSION sess, S24XXERR *err, const char *opcmd, u16 *flags )
{
	char cmd[50];			// command buffer

	// Build and execute the shell command. In all shell commands, the flag words are ordered MSW first.
	sprintf( cmd, "%s 0x%x 0x%x 0x%x\r\n", opcmd, flags[2], flags[1], flags[0] );
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Command helper - Issue shell command that receives 48 bit flags in 3 words, wait for and process reply.
// Imports:
//	opcmd	- command line prefix (i.e., shell command that precedes flag words).
//	flags[]	- receives bit flags, words ordered LSW first.
// Returns TRUE if command successfully executed.

static BOOL ExecCmdReadFlags( HSESSION sess, S24XXERR *err, const char *opcmd, u16 *flags )
{
	char rsp[50];
	BOOL rtnval;

	// Execute shell command and convert flag words from ascii hex to numeric. In all shell commands, the flag words are ordered MSW first.
	if ( ( rtnval = SessionExecCmd( sess, err, 2410, opcmd, 20, rsp ) ) == TRUE )
		sscanf( rsp, "%hx %hx %hx", &flags[2], &flags[1], &flags[0] );

	return rtnval;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////  DIGITAL I/O FUNCTIONS  /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////
// API: Program 48 digital outputs.
// Returns TRUE upon success, else FALSE.
// Imports:
//	states[3] - Lo,Mid,Hi dout states.

S24XX_API BOOL __stdcall s2410_WriteDout( HSESSION sess, S24XXERR *err, u16 *states )
{
	return ExecCmdWriteFlags( sess, err, "wdo", states );
}

/////////////////////////////////////////////////////////////////////////////////
// API: Return programmed digital output states for 48 digital output channels.
// Imports:
//	states[3] - buffer that will receive Lo,Mid,Hi dout states.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_ReadDout( HSESSION sess, S24XXERR *err, u16 *states )
{
	return ExecCmdReadFlags( sess, err, "rdo\r\n", states );
}

////////////////////////////////////////////////////
// API: Return 48 debounced digital input states.
// Imports:
//	states[3] - buffer that will receive Lo,Mid,Hi din states.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_ReadDin( HSESSION sess, S24XXERR *err, u16 *states )
{
	return ExecCmdReadFlags( sess, err, "rdi\r\n", states );
}

///////////////////////////////////////////////////////////////////
// API: Program debounce interval for one digital output channel.
// Imports:
//	chan	- channel number in range 0 to 47.
//	msec	- debounce interval in milliseconds, range 0 to 255.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_SetDebounceTime( HSESSION sess, S24XXERR *err, u8 chan, u8 msec )
{
	char cmd[20];	// command buffer
	
	if ( chan > 47 )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wdbt %d %d\r\n", chan, msec );
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );
}

////////////////////////////////////////////////////////////////
// API: Program operating mode of one digital output channel.
// Imports:
//	chan	- channel number in range 0 to 47.
//	pwmMode	- DOUT_MODE_STANDARD | DOUT_MODE_PWM.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_SetDoutMode( HSESSION sess, S24XXERR *err, u8 chan, S2410_DOUT_MODE pwmMode )
{
	char cmd[20];	// command buffer

	if ( chan > 47 )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wdom %d %s\r\n", chan, pwmMode ? "pwm" : "std" );
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );
}

//////////////////////////////////////////////////////////////////////////////
// API: Program duty cycle for digital output channel operating in PWM mode.
//	chan	- channel number in range 0 to 47.
//	ontime	- on time in milliseconds.
//	offtime	- off time in milliseconds.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_WritePwm( HSESSION sess, S24XXERR *err, u8 chan, u16 ontime, u16 offtime )
{
	char cmd[30];	// command buffer

	if ( chan > 47 )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wpwm %d 0x%x 0x%x\r\n", chan, ontime, offtime );
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  EVENT CAPTURE SYSTEM FUNCTIONS  /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// These functions may be called from the primary application thread to access the 2410's event capture system.
// They can be used in place of, or in addition to, the asynchronous event command functions, which rely on
// an application callback function to process events, whereas these functions process events snychronously
// (serially) by issuing commands and blocking until replies arrive.

// Note: these should not be called from the app's event callback, if there is one.



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// API: Return 48 capture flags and, if no async capture notification client is registered, clear the flags on server.
// Imports:
//	states[3] - buffer that will receive Lo,Mid,Hi din capture flags.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2410_ReadCapFlags( HSESSION sess, S24XXERR *err, u16 *flags )
{
	char rsp[50];
	BOOL rtnval;

	// Execute command and convert samples from cleartext to numeric.
	if ( ( rtnval = SessionExecCmd( sess, err, 2410, "cap read\r\n", 20, rsp ) ) == TRUE )
		sscanf( rsp, "%hx %hx %hx", &flags[0], &flags[1], &flags[2] );

	return rtnval;
}

// API: Set capture inactivity timer. This will cause an event message to be issued if no
// events are detected with specified milliseconds.
S24XX_API BOOL __stdcall s2410_WriteCapTimer( HSESSION sess, S24XXERR *err, u16 msec )
{
	char cmd[20];			// command buffer

	// Build and execute command.
	sprintf( cmd, "cap tout 0x%x\r\n", msec );
	return SessionExecCmd( sess, err, 2410, cmd, 0, NULL );
}

// API: Set capture edge polarity for all DIN channels.
S24XX_API BOOL __stdcall s2410_WriteCapPolarity( HSESSION sess, S24XXERR *err, u16 *flags )
{
	return ExecCmdWriteFlags( sess, err, "cap pol", flags );
}

// API: Disable capture on the specified DIN channels.
S24XX_API BOOL __stdcall s2410_WriteCapDisable( HSESSION sess, S24XXERR *err, u16 *flags )
{
	return ExecCmdWriteFlags( sess, err, "cap disable", flags );
}

// API: Enable continuous capture on the specified DIN channels.
S24XX_API BOOL __stdcall s2410_WriteCapContinuous( HSESSION sess, S24XXERR *err, u16 *flags )
{
	return ExecCmdWriteFlags( sess, err, "cap cont", flags );
}

// API: Enable one-shot capture on the specified DIN channels.
S24XX_API BOOL __stdcall s2410_WriteCapOneshot( HSESSION sess, S24XXERR *err, u16 *flags )
{
	return ExecCmdWriteFlags( sess, err, "cap one", flags );
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////  ASYNCHRONOUS EVENT MONITOR THREAD  /////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Private: attributes of application event callback.
// The details of this are not visible to app.
typedef struct EVENTCLIENT_STRUCT {
	HSESSION	sess;					// Attached session.
	EVENT_CBK	callback;				// Callback function.
	THREAD		thread;					// Handle to CapMonitor thread.
} EVENTCLIENT;


////////////////////////////////////////////////////////////////////////////////////////
// Event monitor/notification thread.

// Helper: convert four contiguous ascii hex digits to 16-bit unsigned binary value.
static u16 cvt4( const char *aschex )
{
	char buf[5];
	*(u32*)buf = *(u32*)aschex;				// copy 4 ascii hex chars to buf
	buf[4] = 0;								// convert to asciiz string
	return (u16)strtol( buf, NULL, 16 );	// convert to binary and return it
}

// Notification thread. This waits for event messages and, whenever a message is received, forwards it to app via callback.
static THREAD CapMonitorThread( EVENTCLIENT *client )
{
	char		*linebuf;
	u16			binbuf[3];
	BOOL		eof = FALSE;
	S24XXERR	err = ERR_NONE;

	// Do an initial app callback to notify client that it has attached. The notification client can use
	// this opportunity to set up idle cap timeout, configure capture edges, enable captures, etc.
	client->callback( CAPMSG_ATTACH, NULL );	// "Attached"

	// Repeat until CAPMSG_DETACH or empty message (indicating closed connection) received ...
	do
	{
		// Wait for next async notification message from 2410. We will disregard err and rely on line length
		// of zero to indicate fatal error or connection closed.
		linebuf = SessionReadUntilPrompt( client->sess, &err, TRUE );

		// Decode message type. Extract msgtype, convert ascii hex data to binary, and pass to app via callback.
		switch ( linebuf[0] )
		{
		case 0:
			// Notify client that the connection closed unexpectedly.
			linebuf[0] = CAPMSG_ERROR;		// conn closed -- mod msgtype accordingly
			client->callback( linebuf[0], binbuf );

			// Notify client that no more callbacks will be forthcoming.
			eof = TRUE;
			linebuf[0] = CAPMSG_DETACH;
			break;

		case CAPMSG_DETACH:
			eof = TRUE;
			break;

		case CAPMSG_NACK:
		case CAPMSG_ERROR:
			break;

		case CAPMSG_TIMER:
			binbuf[0] = cvt4( &linebuf[1] );
			break;

		case CAPMSG_POLARITY:
		case CAPMSG_CONTINUOUS:
		case CAPMSG_ONESHOT:
		case CAPMSG_DISABLE:
		case CAPMSG_EVENT:
			binbuf[2] = cvt4( &linebuf[1] );	// MSW
			binbuf[1] = cvt4( &linebuf[5] );
			binbuf[0] = cvt4( &linebuf[9] );	// LSW
			break;

		default:
			linebuf[0] = CAPMSG_ERROR;		// unknown msgtype -- mod msgtype to indicate error
			break;
		}

		// Pass message info to application's notification client via callback. Note that the callback's context
		// is that of this notification thread.
		client->callback( linebuf[0], binbuf );
	}
	while ( !eof );

	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////  ASYNCHRONOUS EVENT COMMAND FUNCTIONS  ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// These functions are called to start/stop asynchronous event notification callbacks, and to issue
// capture commands from within callbacks. With the exception of s2410_AsyncCapBegin()
// and s2410_AsyncCapEnd(), these functions should only be called by the application's
// capture event callback.


/////////////////////////////////////////////////////////////////////////////////////////////////
// Async command helper - Issue capture system command that requires zero or more flag words.
// Note: this doesn't wait for the command reply as other async messages may arrive first.
// Imports:
//	msgtype	- message type code.
//	flags[]	- logic 1's specify affected channels, words ordered LSW first.
//	nwords	- number of words in flags[].
// Returns TRUE if command successfully issued.

static BOOL AsyncCapCommand( HEVCAP EventHandler, S24XXERR *err, const char msgtype, u16 *flags, int nwords )
{
	char cmd[20];		// command buffer -- must be large enough to hold largest async cap cmd
	char *pbuf = cmd;

	int len = 3 + 4 * nwords;		// msgtype + CRLF + nwords * 4_asciihex_chars_per_word

	// Abort if event callback not registered.
	if ( EventHandler == NULL )
		return FALSE;

	// Construct the async capture command.
	*pbuf++ = msgtype;
	for ( ; nwords > 0; nwords-- )
		pbuf += sprintf( pbuf, "%04x", *flags++ );
	sprintf( pbuf, "\r\n" );

	// Send command to 2410. This is sent via the session that is attached to CapMonitorThread, so the reply will be received by that
	// thread (and therefore we don't expect to receive reply here, nor will we wait for it), which will in turn generate a callback.
	return ( SessionStreamWrite( ((EVENTCLIENT*)EventHandler)->sess, err, cmd, len, TRUE ) == len );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ASYNC API: Install a callback that is to be invoked whenever capture events are detected or capture system command replies are received.
// Imports:
//	ipaddr		- asciiz string containing 2410 IP address.
//	port		- telnet port number used by 2410 (default == 23).
//	callback	- application callback function.
// Returns handle to capture system, which can be used to unregister the callback or issue commands to the capture system.
// NOTE: APP MUST UNREGISTER THE CALLBACK BEFORE TERMINATING!

S24XX_API HEVCAP __stdcall s2410_AsyncCapBegin( const char *ipaddr, S24XXERR *err, u16 port, EVENT_CBK callback, u32 msec )
{
	// Create EventClientInfo object. Abort if failed.
	EVENTCLIENT	*client = (EVENTCLIENT*)malloc( sizeof(EVENTCLIENT) );
	if ( client == NULL )
		return NULL;

	// Init the object: register application's event notification callback; indicate session and thread not yet created.
	client->callback	= callback;
	client->sess		= NULL;
	client->thread		= NULL;

	// Create a new telnet session on 2410 that will be dedicated to event monitoring. If successful ...
	if ( SessionOpen( &client->sess, err, 2410, ipaddr, port, msec, 0 ) )
	{
		// Disable session timeout. If successful ...
		if ( s24xx_SetTimeout( client->sess, err, 0, UNITS_SECONDS, ACTION_NONE ) )
		{
			// Send Attach command via new session. This will fail if another session is already attached. If successful ...
			if ( SessionExecCmd( client->sess, err, 2410, "cap\r\n", 0, NULL ) )
			{
				// Create a private notification thread that blocks while waiting for notification messages and, when received, calls the app callback in its context.
				if ( ( client->thread = osdThreadCreate( CapMonitorThread, client, FALSE ) ) != NULL )
					return client;
			}
		}
	}

	// The attach failed, so free resources.
	SessionClose( client->sess );
	free( client );

	return NULL;	// Failed to attach.
}

//////////////////////////////////////////////////////////////////////////////
// ASYNC API: Uninstall a previously installed capture event callback.
// Imports:
//	callback	- application callback function.
// Returns handle to capture system, which can be used to unregister the callback or issue commands to the capture system.
// NOTE: AFTER REGISTERING A CALLBACK, THE APP MUST CALL THIS TO UNREGISTER CALLBACK BEFORE TERMINATING!

S24XX_API BOOL __stdcall s2410_AsyncCapEnd( HEVCAP client, S24XXERR *err )
{
	// Send a CapDetach command to 2410 (abort if failed). CapMonitorThread will terminate when it receives the reply.
	if ( !AsyncCapCommand( client, err, CAPMSG_DETACH, NULL, 0 ) )
		return FALSE;

	// Wait for CapMonitorThread to terminate.
	osdThreadWaitTerminate( ((EVENTCLIENT*)client)->thread );

	// Free resources.
	SessionClose( ((EVENTCLIENT*)client)->sess );
	free( client );

	return TRUE;	// Successfully detached.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ASYNC API: Configure capture system to invoke callback if specified time elapses before any events are captured.
// The timer will automatically be cancelled by the 2410 if an event occurs before timeout.
// Imports:
//	msec - time interval in milliseconds.
// Returns TRUE if command successfully issued.
// Note: this doesn't wait for reply as other async messages may arrive first.

S24XX_API BOOL __stdcall s2410_AsyncCapStartTimer( HEVCAP EventHandler, S24XXERR *err, u16 msec )
{
	// Send an async StartTimer command to 2410. This is sent via the session that is attached to CapMonitorThread, so the reply will be received
	// by that thread (and therefore we don't expect to receive reply here, nor will we wait for it), which will in turn generate a callback.
	return AsyncCapCommand( EventHandler, err, CAPMSG_TIMER, &msec, 1 );
}

//////////////////////////////////////////////////////////////
// ASYNC API: Disable capture on the specified DIN channels.
// Returns TRUE if command successfully issued.

S24XX_API BOOL __stdcall s2410_AsyncCapDisable( HEVCAP EventHandler, S24XXERR *err, u16 *flags )
{
	return AsyncCapCommand( EventHandler, err, CAPMSG_DISABLE, flags, 3 );
}

////////////////////////////////////////////////////////////////////////
// ASYNC API: Enable continuous capture on the specified DIN channels.
// Returns TRUE if command successfully issued.

S24XX_API BOOL __stdcall s2410_AsyncCapContinuous( HEVCAP EventHandler, S24XXERR *err, u16 *flags )
{
	return AsyncCapCommand( EventHandler, err, CAPMSG_DISABLE, flags, 3 );
}

//////////////////////////////////////////////////////////////////////
// ASYNC API: Enable one-shot capture on the specified DIN channels.
// Returns TRUE if command successfully issued.

S24XX_API BOOL __stdcall s2410_AsyncCapOneshot( HEVCAP EventHandler, S24XXERR *err, u16 *flags )
{
	return AsyncCapCommand( EventHandler, err, CAPMSG_DISABLE, flags, 3 );
}

////////////////////////////////////////////////////////////////
// ASYNC API: Set capture edge polarity for all DIN channels.
// Returns TRUE if command successfully issued.

S24XX_API BOOL __stdcall s2410_AsyncCapPolarity( HEVCAP EventHandler, S24XXERR *err, u16 *flags )
{
	return AsyncCapCommand( EventHandler, err, CAPMSG_DISABLE, flags, 3 );
}
