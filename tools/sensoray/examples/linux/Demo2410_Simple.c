///////////////////////////////////////////////////////////////////////////////
// File 	 : Demo2410_Simple.c
// Function  : Simple automated telnet client application for Sensoray 2410.
// Copyright : (C) 2010 Sensoray
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <time.h>

#ifdef OSTYPE_WINDOWS
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>

char getch(void)
{
	char ch;
	struct termios old;
	struct termios new;

	// Initialize new terminal i/o settings
	tcgetattr( 0, &old );				// grab old terminal i/o settings
	new = old;							// make new settings same as old settings
	new.c_lflag &= ~( ICANON | ECHO );	// disable buffered i/o, echo mode
	tcsetattr( 0, TCSANOW, &new );		// use these new terminal i/o settings now

	ch = getchar();

	tcsetattr( 0, TCSANOW, &old );		// Restore old terminal i/o settings
	return ch;
}

 
void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int _kbhit(void)
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
}
#endif
#include "s24xx.h"

// Configuration constants.
#define DEFAULT_TIMEOUT 		1000		// Transaction timeout in milliseconds. Increase this if connected via WAN.
#define TELNET_PORTNUM			23			// Use standard telnet port number.

// Forward declaration.
static void IoLoop( HSESSION *sess, const char *ipaddr, u16 port );

// Storage.
static HEVCAP	hEvcap = NULL;		// Handle to async capture system, which can be used to issue async capture commands.
static HSESSION sess;


///////////////////////////////////////
// Application main function.
// Invocation: APPNAME IPADDR
// Example: Demo2410_Simple 192.168.24.10

int main( int argc, char *argv[] )
{
	S24XXERR err = ERR_NONE;

	// Validate command line.
#ifdef OSTYPE_LINUX
    changemode(1);
#endif
	if ( argc != 2 )
		printf( "Error: Invocation error\nUsage: %s ipaddr\n", argv[0] );

	// Open the api.
	else if ( !s24xx_ApiOpen() )
		printf( "Error: Failed to open session interface\n" );

	// Open telnet session and get its handle.
	else if ( !s24xx_SessionOpen( &sess, &err, 2410, argv[1], TELNET_PORTNUM, DEFAULT_TIMEOUT ) ) {
		s24xx_ErrorText( err ) ;
        printf("session failed\n");
    } else {
// Run i/o loop and then close the api.
		IoLoop( sess, argv[1], TELNET_PORTNUM ); 	// Run the i/o processing loop.

		s24xx_SessionClose( sess );		// Terminate connection.
		s24xx_ApiClose();				// Free API resources.
	}
#ifdef OSTYPE_LINUX
    changemode(0);
#endif
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Application event callback. Must have these arguments:
//	msgtype	- notification message type code.
//	val		- pointer to array of u16 argument values.

static void EventCallback( char msgtype, const u16 *val )
{
	S24XXERR err = ERR_NONE;

	switch ( msgtype )
	{
	case CAPMSG_ATTACH:			// 'aNNNN'		- attach to specified TxStream object (NNNN = stream object)
		printf( "begin\n" );
		s2410_AsyncCapStartTimer( hEvcap, &err, 10000 );	// start timer -- timeout in 10 seconds if no capture events
		break;
	case CAPMSG_DETACH:			// 'q'			- detach from attached TxStream object
		printf( "quit\n" );
		break;
	case CAPMSG_NACK:			// 'n'			- capture command NACK
		printf( "nack\n" );
		break;
	case CAPMSG_ERROR:			// 'e'			- capture command error
		printf( "error\n" );
		break;
	case CAPMSG_TIMER:			// 'tNNNN'		- start capture inactivity timer and set it to timeout in NNNN milliseconds
		printf( "start timer: %d msec\n", val[0] );
		break;
	case CAPMSG_POLARITY:		// 'pNNNNNN'	- set polarity (NNNNNN = 48-bit binary data)
		printf( "pol:  %04x %04x %04x\n", val[2], val[1], val[0] );
		break;
	case CAPMSG_CONTINUOUS:		// 'cNNNNNN'	- enable continuous capture (NNNNNN = 48-bit binary data)
		printf( "cont:  %04x %04x %04x\n", val[2], val[1], val[0] );
		break;
	case CAPMSG_ONESHOT:		// 'oNNNNNN'	- enable one-shot capture (NNNNNN = 48-bit binary data)
		printf( "1shot: %04x %04x %04x\n", val[2], val[1], val[0] );
		break;
	case CAPMSG_DISABLE:		// 'dNNNNNN'	- disable capture (NNNNNN = 48-bit binary data)
		printf( "disab: %04x %04x %04x\n", val[2], val[1], val[0] );
		break;
	case CAPMSG_EVENT:			// 'vNNNNNN'	- capture event (NNNNNN = 48-bit binary data)
		if ( ( val[0] | val[1] | val[2] ) != 0 )
			printf( "event: %04x %04x %04x\n", val[2], val[1], val[0] );
		else
		{
			printf( "timeout\n" );							// timed out -- no events occurred since timer started
			s2410_AsyncCapStartTimer( hEvcap, &err,  10000 );		// restart inactivity timer -- timeout in 10 seconds
		}
		break;
	}
}

//////////////////////////////////////
// Main I/O processing loop.

static void IoLoop( HSESSION *sess, const char *ipaddr, u16 port )
{
	u16 douts[3] = { 0, 0, 1 };

	u16 flags[3];

	S24XXERR err = ERR_NONE;

	// Set session timeout to 5 seconds. Don't reset i/o upon timeout.
//	s24xx_SetTimeout( sess, 5, UNITS_SECONDS, ACTION_NONE );
    printf("io loop.\n Loops through outputs on 2410.  \nPress any key to exit\n");
	// Reset all I/O on server.
	s24xx_ResetIo( sess, &err );

	// Set LED intensity to a pleasant level.
	s2410_SetLedBrightness( sess, &err, 50 );

/*
	// Activate pwm mode for some dout channels, using arbitrary timing values.
	srand( (unsigned)time( NULL ) );	// seed randomizer
	for ( dioChan = 0; dioChan < 48; dioChan++ )
	{
		s2410_SetDoutMode( sess, dioChan, MODE_PWM );
		s2410_WritePwm( sess, dioChan, (u16)( ( rand() & 0x03FF ) + 1 ), (u16)( ( rand() & 0x03FF ) + 1 ) );
	}
*/

	// Set up async capture notification.
	flags[0] = flags[1] = flags[2] = 0;
	s2410_WriteCapDisable( sess, &err, flags );
	hEvcap = s2410_AsyncCapBegin( ipaddr, &err, port, EventCallback, DEFAULT_TIMEOUT );

	// Execute the i/o processing loop a few times, approximately ten times per second.
	do
//	for ( iters = 0; iters < 10000; iters++ )
	{
		// Write counts to digital outputs.
		s2410_WriteDout( sess, &err, douts );

		// Read debounced digital inputs.
//		s2410_ReadDin( sess, dins );

		// Abort if error detected.
		if ( err )
		{
			printf( "Error: %s\n", s24xx_ErrorText( err ) );
			break;
		}

		// Shift pattern that will be sent do digital outputs on next tick.
		if ( douts[2] )
		{
			douts[2] <<= 1;
			if ( !douts[2] )
				douts[1] = 1;
		}
		else if ( douts[1] )
		{
			douts[1] <<= 1;
			if ( !douts[1] )
				douts[0] = 1;
		}
		else
		{
			douts[0] <<= 1;
			if ( !douts[0] )
				douts[2] = 1;
		}

		// Wait one tick. In a realtime application this should use an ipc mechanism
		// with realtime behavior.
#ifdef OSTYPE_WINDOWS
		Sleep( 1 );
#else
        usleep(1000*1000);
#endif

	}
	while (!_kbhit() );	// exit loop if key pressed

	getch();

	// Turn off asynchronous capture notification.
	s2410_AsyncCapEnd( hEvcap, &err );
}
