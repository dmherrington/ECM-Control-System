////////////////////////////////////////////////////////////////////////////////
// File			: s24xx.c
// Function		: Common API for Sensoray 24xx Ethernet I/O Servers
// Target		: OS-independent
// Author		: Jim Lamberson
// Copyright	: Copyright (C) 2010 Sensoray
////////////////////////////////////////////////////////////////////////////////


#define VERSION_INFO	"Ver.1.0.1"		// *** BUMP THIS EACH RELEASE ***


#include <stdio.h>
#include <string.h>

#define S24XX_EXPORTS

#include "osi_wrapper.h"
#include "s24xx.h"
#include "session.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DIAGNOSTICS  ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// Enable access to rootmode commands.

S24XX_API BOOL __stdcall s24xx_EnterRootMode( HSESSION sess, S24XXERR *err )
{
	return SessionExecCmd( sess, err, 0, "rootuser\r\n", 0, NULL );
}

///////////////////////////////////////////////////////
// Error functions.

// Return pointer to descriptive error string.
S24XX_API const char * __stdcall s24xx_ErrorText( S24XXERR err )
{
	switch ( err )
	{
	case ERR_NONE:					return "No errors";
// Initialization errors:
	case ERR_MALLOC:				return "Memory allocation failed";
	case ERR_SOCKETCREATE:			return "Can't create socket";
	case ERR_SESSIONCONNECT:		return "Can't connect to server";
	case ERR_TOOMANYSESSIONS:		return "Maximum server connections";
	case ERR_OPENSHELL:				return "Failed to receive shell signon message";
	case ERR_THREADCREATE:			return "Can't create thread";
	case ERR_CRITSECTCREATE:		return "Can't create critical section";
	case ERR_CREATEMUTEX:			return "Can't create mutex";
// Fatal run-time errors:
	case ERR_INVALIDSESSION:		return "Invalid session handle";
	case ERR_SOCKET:				return "Socket error";
	case ERR_CONNCLOSED:			return "Session closed";
	case ERR_NETWORKWRITE:			return "Socket write failed";
	case ERR_TIMEOUT:				return "Response timeout";
// Non-fatal run-time errors:
	case ERR_COMPORTATTACH:			return "Comport failed to attach to session";
	case ERR_SHELLCOMMAND:			return "Shell command error";
	case ERR_RSPSIZE:				return "Unexpected response size";
	case ERR_CMDARG:				return "Invalid command argument";
	case ERR_BUFWOULDOVERFLOW:		return "Operation would overflow buffer";
	case ERR_COMPORTWASATTACHED:	return "Comport is attached. Attempted to reattach or execute a non-comport transaction";
	case ERR_COMPORTUNATTACHED:		return "Comport not attached and app tried to execute comport transaction";
// Other errors:
	default:						return "Unknown error";
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////  API & SESSION MANAGEMENT  ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////
// Open/close 24xx API.

S24XX_API BOOL __stdcall s24xx_ApiOpen( void )
{
	return SessionApiOpen();
}

S24XX_API void __stdcall s24xx_ApiClose( void )
{
	SessionApiClose();
}

////////////////////////////////////////////
// Return middleware version info.

S24XX_API const char * __stdcall s24xx_VersionInfo( void )
{
	return VERSION_INFO;
}

//////////////////////////////////////////////////////////////////////////////////
// Create session object and use it to open a telnet session to 24xx I/O server.
// Opens telnet session at specified ip address and sync's to shell.
// Returns 0 if successful, else error code.

S24XX_API BOOL __stdcall s24xx_SessionOpen( HSESSION *psess, S24XXERR *err, u16 svrModel, const char *ipaddr, u16 port, u32 msec )
{
	return SessionOpen( psess, err, svrModel, ipaddr, port, msec, 0 );
}

////////////////////////////////////////////////////////////////////////////////////
// If session object exists, close session (if active) and destroy session object.

S24XX_API void __stdcall s24xx_SessionClose( HSESSION sess )
{
	SessionClose( sess );
}

///////////////////////////////////////////////////////////////////////////////////
// Restart board. Note: under normal conditions this may return an error,
// depending on whether reply arrives.

S24XX_API BOOL __stdcall s24xx_Reboot( HSESSION sess, S24XXERR *err, BOOL configmode )
{
	// Invoke reboot on 24xx.
	BOOL rtnval = SessionExecCmd( sess, err, 0, configmode ? "reboot config\r\n" : "reboot normal\r\n", IGNORE_EXPECTEDRSPSIZE, NULL );
	
	// Wait for the reboot to begin.
	osdThreadSleep( 100 );

	return rtnval;
}

///////////////////////////////////////////////////////////////////////////////////
// Reset all I/O on board.
// Returns TRUE if successful.

S24XX_API BOOL __stdcall s24xx_ResetIo( HSESSION sess, S24XXERR *err )
{
	return SessionExecCmd( sess, err, 0, "reset\r\n", 0, NULL );
}

//////////////////////////////////////////////////////////////////////////
// Fetch version info strings from board.
// Imports:
//	buf				- buffer to receive version number string. Set to NULL to ignore.
//	bufsize			- size of buf[].
//	isSecondaryFw	- boolean that receives TRUE if secondary fw is executing. Set to NULL to ignore.
// Returns TRUE if successful.

S24XX_API BOOL __stdcall s24xx_GetVersionInfo( HSESSION sess, S24XXERR *err, char *buf, u32 bufsize, BOOL *isSecondaryFw )
{
	char seps[] = " ";		// Info delimiter.
	char info[100];			// Version info string from I/O server.
	char *version;			// Pointer to version string in info[].
	char *image;			// Pointer to fw image identifier in info[].
	BOOL isSecImage;

	// Fetch version info from I/O server. Abort if no reply or reply won't fit into info[].
	if ( SessionExecCmd( sess, err, 0, "ver\r\n", -(int)sizeof(info), info ) )		// ignore response size -- we will evaluate it here
	{
		// Split info string into fields.
		version = strtok( info, seps );
		image = strtok( NULL, seps );

		// Decode image identifier -- abort if missing or not recognized as valid id.
		if ( image == NULL )
			*err = ERR_RSPSIZE;	// missing
		else if ( strcmp( image, "pri" ) == 0 )
			isSecImage = FALSE;
		else if ( strcmp( image, "sec" ) == 0 )
			isSecImage = TRUE;
		else
			*err = ERR_RSPSIZE;	// invalid id

		if ( *err == ERR_NONE )
		{
			// Copy image identifier to user.
			if ( isSecondaryFw != NULL )
				*isSecondaryFw = isSecImage;

			// Copy version number string to user buffer.
			if ( buf != NULL )
			{
				// Abort if version string won't fit into user buffer.
				if ( strlen(version) >= bufsize )
					*err = ERR_BUFWOULDOVERFLOW;
				else
					strcpy( buf, version );
			}
		}
	}

	return ( *err == ERR_NONE );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  FIRMWARE ACCESS  ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
// Enable flash erase and write.
// Returns TRUE if successful.

S24XX_API BOOL __stdcall s24xx_FirmwareWriteEnable( HSESSION sess, S24XXERR *err )
{
	return SessionExecCmd( sess, err, 0, "rootuser\r\n", 0, NULL );
}

//////////////////////////////////////////////////////////
// Erase secondary firmware and mark it inactive.
// Note: this will fail if session not operating in rootmode.
// Returns TRUE if successful.

S24XX_API BOOL __stdcall s24xx_FirmwareErase( HSESSION sess, S24XXERR *err )
{
	BOOL rtnval;

	// Mark secondary firmware invalid and, if not currently executing secondary firmware, erase it. If this fails then
	// it's likely that the fw has been invalidated, but we can't erase it because cpu is currently executing from it.
	rtnval = SessionExecCmd( sess, err, 0, "epf\r\n", 0, NULL );

	// Clear error if it resulted from the server executing secondary (vs. primary) firmware.
	if ( *err == ERR_RSPSIZE )	// if recoverable error
		*err = ERR_NONE;

	return rtnval;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Mark secondary firmware active. This should not be executed until new firmware
// has been written to flash via the requisite number of calls to s24xx_FirmwareUpload.
// Note: this will fail if session not operating in rootmode.
// Returns TRUE if successful.

S24XX_API BOOL __stdcall s24xx_FirmwareActivate( HSESSION sess, S24XXERR *err )
{
	return SessionExecCmd( sess, err, 0, "apf\r\n", 0, NULL );
}

////////////////////////////////////////////////////////////////////////////////////////
// Read 16-byte firmware chunk from I/O server, as 32-byte string of ascii hex chars.
// Entry:
//	flashaddr	- starting physical flash address; must be on a 16-byte address boundary -- THIS IS NOT CHECKED HERE.
//	buf			- buffer that will receive the chunk; must have at least 32-char capacity.
// Returns TRUE if successful.

static BOOL ReadFirmwareChunk( HSESSION sess, S24XXERR *err, u32 flashaddr, char *buf )
{
	char cmd[20];		// command buffer
	char rsp[33];
	BOOL rtnval;
	
	// Read firmware chunk from I/O server.
	sprintf( cmd, "rpf 0x%x\r\n", (uint)flashaddr );	// build cmd
	if ( ( rtnval = SessionExecCmd( sess, err, 0, cmd, 32, rsp ) ) != FALSE )
		memcpy( buf, rsp, 32 );		// note: not a string copy -- copy without null string terminator

	return rtnval;
}

/////////////////////////////////////////////////////////////////////////
// Write 16-byte firmware chunk to I/O server (as 32 ascii hex chars).
// Entry:
//	flashaddr	- first contiguous address to be written in flash
//	buf			- buffer containing binary data to be written to flash
// Returns TRUE if successful.

static BOOL WriteFirmwareChunk( HSESSION sess, S24XXERR *err, u32 flashaddr, char *buf )
{
	int		i;
	char	cmd[50];		// command buffer

	// Construct I/O server command line.
	char *pcmd = cmd + sprintf( cmd, "wpf 0x%x ", (uint)flashaddr );	// build cmd
	for ( i = 0; i < 16; i++ )
		pcmd += sprintf( pcmd, "%02x", (u8)buf[i] );
	sprintf( pcmd, "\r\n" );

	// Send firmware chunk to I/O server, whereupon it will be immediately written to flash.
	return SessionExecCmd( sess, err, 0, cmd, 0, NULL );		// execute cmd
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Write contiguous block of firmware quadlets to flash memory (secondary firmware image).
// Imports:
//	buf					- contiguous binary data to be written to flash.
//	nbytes				- number of bytes to write; must be a multiple of 4.
//	ProgressCallback	- application callback that displays progress. Set to NULL for no callbacks.
//	CallbackFreq		- specifies callback frequency: one call every Nth chunk write.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s24xx_FirmwareUpload( HSESSION sess, S24XXERR *err, u32 flashaddr, u8 *buf, u32 nbytes, PROGRESS_CALLBACK ProgressCallback, u32 CallbackFreq )
{
	char	padbuf[32];
	u32		nWholeChunks;						// number of whole 16-byte chunks to be written out
	u32		callbackTimer = CallbackFreq;

	// Data must be written to I/O server as 16-byte chunks, aligned on 16-byte address boundaries, using repeated "wpf" commands.

	// If flash starting address isn't 16-byte aligned ...
	u32 padBeg = flashaddr & 0x0000000F;		// Number of padding bytes at beginning of first chunk. Equals zero if full-sized chunk.
	if ( padBeg )
	{
		// Read existing flash data and use it to pad the beginning of the first 16-byte chunk so that existing
		// flash data (preceding new data, but within 16-byte group we are now writing) will not be corrupted.
		u32 wrBeg = 16 - padBeg;	// Number of data bytes in first chunk.
		if ( wrBeg > nbytes )		// First chunk can't be larger than total data size.
			wrBeg = nbytes;

		flashaddr &= 0xFFFFFFF0;	// Flash chunks always start on 16-byte address boundaries.

		if ( !ReadFirmwareChunk( sess, err, flashaddr, padbuf ) )	// Populate padding buffer with existing flash data.
			return FALSE;

		memcpy( padbuf + padBeg, buf, wrBeg );						// Overwrite padding that will be replaced by new data.

		if ( !WriteFirmwareChunk( sess, err, flashaddr, padbuf ) )	// Write chunk to flash.
			return FALSE;

		nbytes		-= wrBeg;		// Consume bytes from total count.
		buf			+= wrBeg;		// Advance source data buffer pointer.
		flashaddr	+= 16;			// Advance flash address to next chunk.
	}

	// Write all whole chunks to flash (i.e., whole 16-byte chunks that require no padding).
	for ( nWholeChunks = nbytes >> 4; nWholeChunks > 0; nWholeChunks--, nbytes -= 16, flashaddr += 16, buf += 16 )
	{
		if ( WriteFirmwareChunk( sess, err, flashaddr, (char*)buf ) != TRUE )
			return FALSE;

		// Progress indicator.
		if ( ProgressCallback != NULL )
		{
			if ( --callbackTimer == 0 )
			{
				ProgressCallback( nbytes );		// Update progress.
				callbackTimer = CallbackFreq;	// Reset timer for next update.
			}
		}
	}

	// If any data remains, write the final, fractional chunk to flash.
	if ( nbytes > 0 )
	{
		if ( !ReadFirmwareChunk( sess, err, flashaddr, padbuf ) )		// Populate padding buffer with existing flash data
			return FALSE;

		memcpy( padbuf, buf, nbytes );									// Overwrite padding that will be replaced by new data.

		if ( !WriteFirmwareChunk( sess, err, flashaddr, padbuf ) )		// Write chunk to flash.
			return FALSE;

		nbytes = 0;		// done
	}

	// If finished uploading firmware ...
	if ( nbytes == 0 )
		if ( ProgressCallback != NULL )
			ProgressCallback( 0 );		// Final progress update.

	return TRUE;	// success
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////  TIME  //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
// Program communication timeout interval for telnet session.
// Imports:
//	timeout	- time interval.
//	seconds	- time interval units: MILLISECONDS | SECONDS
//	reset	- timeout response: NONE | RESET
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s24xx_SetTimeout( HSESSION sess, S24XXERR *err, u32 timeout, S24XX_TOUT_UNITS seconds, S24XX_TOUT_RESPONSE reset )
{
	char cmd[30];	// command buffer

	// Build and execute command.
	sprintf( cmd, "wto %d %s %s\r\n", (uint)timeout, seconds ? "s" : "ms", reset ? "rst" : "norst" );
	return SessionExecCmd( sess, err, 0, cmd, 0, NULL );
}

/////////////////////////////////////////////////
// Return current timestamp clock.
//	time - buffer that will receive timestamp
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s24xx_ReadTimestamp( HSESSION sess, S24XXERR *err, u32 *time )
{
	BOOL rtnval;
	char rsp[50];

	// Execute command and convert time from cleartext to numeric.
	if ( ( rtnval = SessionExecCmd( sess, err, 0, "rtime\r\n", 10, NULL ) ) != FALSE )
		sscanf( rsp, "%x", (uint*)time );

	return rtnval;
}

/////////////////////////////////////////////
// Program timestamp clock.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s24xx_WriteTimestamp( HSESSION sess, S24XXERR *err, u32 time )
{
	char cmd[20];	// command buffer

	// Build and execute command.
	sprintf( cmd, "wtime 0x%x\r\n", (uint)time );
	return SessionExecCmd( sess, err, 0, cmd, 0, NULL );
}
