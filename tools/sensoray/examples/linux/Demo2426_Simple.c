///////////////////////////////////////////////////////////////////////////////
// File 	 : Demo2426_Simple.c
// Function  : Simple demo application for Sensoray 2426.
// Copyright : (C) 2008 Sensoray
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
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
static void IoLoop( HSESSION *sess );


/////////////////////////////////////////////////
// Application main function.
// Invocation: APPNAME IPADDR
// Example: Demo2426_Simple 192.168.24.26

int main( int argc, char *argv[] )
{
	HSESSION sess;
	S24XXERR err = 0;
#ifdef OSTYPE_LINUX
    changemode(1);
#endif

	// Validate command line.
	if ( argc != 2 )
		printf( "Error: Invocation error\nUsage: %s ipaddr\n", argv[0] );

	// Open the api.
	else if ( !s24xx_ApiOpen() )
		printf( "Error: Failed to open session interface\n" );

	// Create session object and open the telnet session.
	else if ( !s24xx_SessionOpen( &sess, &err, 2426, argv[1], TELNET_PORTNUM, 2000 ) )
		s24xx_ErrorText( err ) ;
	
	// Run i/o loop and then close the api.
	else
	{
		IoLoop( sess ); 	// Run the i/o processing loop.

		s24xx_SessionClose( sess );		// Terminate telnet connection.
		s24xx_ApiClose();				// Free API resources.
	}
#ifdef OSTYPE_LINUX
    changemode(0);
#endif
    return 0;
}

//////////////////////////////////////
// Main I/O processing loop.

static void IoLoop( HSESSION *sess )
{
	S2426_ADC_SAMPLE samp[8];
	int	iters;
    S24XXERR err = 0;
	u8	dioChan;
	u32	EncoderCounts;			// Snapshot of encoder counts and acquisition time.
	u32	EncoderTimestamp;
	u8	dinDebounced;			// Snapshot of debounced dins.

	// Set session timeout to 5 seconds. Don't reset i/o upon timeout.
//	s24xx_SetTimeout( sess, &err, 5, UNITS_SECONDS, ACTION_NONE );

	// Set encoder mode.
	s2426_WriteEncoderMode( sess, &err, QUADRATURE_X4, ENC_PRELOAD_DISABLE );

	// Activate pwm mode for dout channels 12-15, using arbitrary timing values.
	for ( dioChan = 12; dioChan < 16; dioChan++ )
	{
		s2426_SetDoutMode( sess, &err, dioChan, DOUT2426_MODE_PWM );
		s2426_WritePwm( sess, &err, dioChan, (u16)( ( 23 * ( dioChan + 1 ) ) & 255 ), (u16)( ( 39 * ( dioChan + 1 ) ) & 511 ) );
	}

	// Execute the i/o processing loop a few times, approximately ten times per second.
	for (iters = 0; iters < 10000; iters++)
	{
		// Read encoder counts.
		s2426_ReadEncoderCounts( sess, &err, &EncoderCounts, &EncoderTimestamp );

		// Write counts to digital outputs.
		s2426_WriteDout( sess, &err, (u16)iters );

		// Read a/d converter.
		s2426_ReadAdc( sess, &err, samp, TRUE );

		// Write counts to dac.
		s2426_WriteAout( sess, &err, (s16)iters, TRUE );

		// Read debounced digital inputs.
		s2426_ReadDin( sess, &err, &dinDebounced, NULL );

		// Abort if error detected.
		if ( err != ERR_NONE )
		{
			printf( "Error: %s\n", s24xx_ErrorText( err ) );
			break;
		}

		// Wait one "tick" time. In a realtime application this should use an ipc mechanism with realtime behavior.
#ifdef OSTYPE_WINDOWS
		Sleep( 1 );
#else
        usleep(1000*1000);
#endif

	}
}
