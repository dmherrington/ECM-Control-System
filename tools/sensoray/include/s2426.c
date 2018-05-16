////////////////////////////////////////////////////////////////////////////////
// File			: s2426.c
// Function		: API for Sensoray 2426
// Target		: OS-independent
// Author		: Jim Lamberson
// Created		: 2008/07/10
// Copyright	: Copyright (C) 2008 Sensoray
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#define S24XX_EXPORTS

#include "osi_wrapper.h"
#include "s24xx.h"
#include "session.h"


// Manifest constants --------------

#define S2426_NUM_DOUTS		16
#define S2426_NUM_DINS		8


//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DIAGNOSTICS  ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
// Diagnostic function: Enable/disable analog input scanning.
// Imports:
//	chan - 0 to 7 locks input on chan, 0xFF enables scanning
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_AdcLockChan( HSESSION sess, S24XXERR *err, u8 chan )
{
	char cmd[20];	// command buffer
	
	if ( chan >= S2426_NUM_ADC_CHANS )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "ailok 0x%x\r\n", chan );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////  DIGITAL I/O  //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////
// Program all 16 digital outputs.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_WriteDout( HSESSION sess, S24XXERR *err, u16 states )
{
	char cmd[20];	// command buffer

	// Build and execute command.
	sprintf( cmd, "wdo %d\r\n", states );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}

/////////////////////////////////////////////////
// Return programmed digital output states.
//	states		- buffer that will receive states
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadDout( HSESSION sess, S24XXERR *err, u16 *states )
{
	char rsp[10];
	BOOL rtnval;

	// Execute command and convert samples from cleartext to numeric.
	if ( ( rtnval = SessionExecCmd( sess, err, 2426, "rdo\r\n", 6, rsp ) ) != FALSE )
		sscanf( rsp, "%hx", states );

	return rtnval;
}

/////////////////////////////////////////////////
// Return debounced digital input states.
// Imports:
//	states		- buffer that will receive states
//	timestamp	- buffer that will receive timestamp. Set to NULL if timestamp not needed.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadDin( HSESSION sess, S24XXERR *err, u8 *states, u32 *timestamp )
{
	u16 data16 = 0;
	char rsp[50];
	BOOL rtnval;

	// Execute command and convert samples from cleartext to numeric.
	if ( timestamp != NULL )
	{
		if ( ( rtnval = SessionExecCmd( sess, err, 2426, "rdi -t\r\n", 15, rsp ) ) != FALSE )
			sscanf( rsp, "%hx %x", &data16, (uint*)timestamp );
	}

	else
	{
		if ( ( rtnval = SessionExecCmd( sess, err, 2426, "rdi\r\n", 4, rsp ) ) != FALSE )
			sscanf( rsp, "%hx", &data16 );
	}

	// Copy state values to app.
	*states	= (u8)data16;

	// Success.
	return rtnval;
}

///////////////////////////////////////////////////////////////
// Program debounce interval for one digital output channel.
// Imports:
//	chan	- channel number in range 0 to 7
//	msec	- debounce interval in milliseconds, range 0 to 255
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_SetDebounceTime( HSESSION sess, S24XXERR *err, u8 chan, u8 msec )
{
	char cmd[20];	// command buffer
	
	if ( chan >= S2426_NUM_DINS )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wdbt %d %d\r\n", chan, msec );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}

/////////////////////////////////////////////////////////
// Program operating mode of one digital output channel.
// Imports:
//	chan	- channel number in range 0 to 15
//	pwmMode	- DOUT_MODE_STANDARD | DOUT_MODE_PWM
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_SetDoutMode( HSESSION sess, S24XXERR *err, u8 chan, S2426_DOUT_MODE pwmMode )
{
	char cmd[20];	// command buffer
	
	if ( chan >= S2426_NUM_DOUTS )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wdom %d %s\r\n", chan, pwmMode ? "pwm" : "std" );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}

/////////////////////////////////////////////////////////////////////////
// Program duty cycle for digital output channel operating in PWM mode.
//	chan	- channel number in range 0 to 15
//	ontime	- on time in milliseconds
//	offtime	- off time in milliseconds
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_WritePwm( HSESSION sess, S24XXERR *err, u8 chan, u16 ontime, u16 offtime )
{
	char cmd[30];	// command buffer

	if ( chan >= S2426_NUM_DOUTS )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wpwm %d 0x%x 0x%x\r\n", chan, ontime, offtime );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////  DAC  /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////
// Program analog output.
//	setpoint - buffer that will receive setpoint
//  calCorrect - set to TRUE to apply calibration correction to setpoint
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_WriteAout( HSESSION sess, S24XXERR *err, s16 setpoint, BOOL calCorrect )
{
	char cmd[20];	// command buffer

	// Build command message.
	if ( calCorrect )
		sprintf( cmd, "wao %d -c\r\n", setpoint );
	else
		sprintf( cmd, "wao %d\r\n", setpoint );
	
	// Execute command.
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}

/////////////////////////////////////////////////
// Return programmed analog output setpoint.
//	setpoint - buffer that will receive setpoint
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadAout( HSESSION sess, S24XXERR *err, s16 *setpoint )
{
	char rsp[50];
	BOOL rtnval;

	// Execute command and convert setpoint from cleartext to numeric.
	if ( ( rtnval = SessionExecCmd( sess, err, 2426, "rao\r\n", 6, rsp ) ) != FALSE )
		sscanf( rsp, "%hx", setpoint );

	return rtnval;
}

/////////////////////////////////////////////
// Set DAC calibration constants in flash.
// Entry:
//	scalar - signed, fixed point (0xNNNN.NNNN) scalar with nominal value slightly smaller than +1.0 (0x00010000).
//	offset - signed, integer offset with nominal value 0.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_SetDacCalConstants( HSESSION sess, S24XXERR *err, s32 scalar, s32 offset )
{
	char cmd[40];	// command buffer

	// Write scalar to onboard ram (flash image). If successful ...
	sprintf( cmd, "wcc 0 0x%x\r\n", (uint)scalar );
	if ( SessionExecCmd( sess, err, 2426, cmd, 0, NULL ) )
	{
		// Write offset to onboard ram (flash image) and, if successful, copy all cal constants from onboard ram image to flash.
		sprintf( cmd, "wcc 1 0x%x\r\n", (uint)offset );
		if ( SessionExecCmd( sess, err, 2426, cmd, 0, NULL ) )
			return SessionExecCmd( sess, err, 2426, "wcf\r\n", 0, NULL );
	}

	return FALSE;	// failed
}

///////////////////////////////////////////////////////////////////////////////////
// Return programmed DAC calibration constants.
// Assumes cal constants previously transferred from 2426 flash to ram image.
// Entry:
//	a - receives dac scalar
//	b - receives dac offset
// Returns TRUE upon success, else FALSE.

// Helper: read one calibration constant.
static BOOL ReadCalConst( HSESSION sess, S24XXERR *err, u32 index, s32 *val )
{
	char	cmd[40];	// command buffer
	char	rsp[40];	// response buffer
	BOOL	rtnval;

	// Fetch quadlet from cal constant image array in ram and convert quadlet from cleartext to numeric.
	sprintf( cmd, "rcc %u\r\n", (uint)index );
	if ( ( rtnval = SessionExecCmd( sess, err, 2426, cmd, 10, rsp ) ) != FALSE )
		sscanf( rsp, "%x", (uint*)val );

	return rtnval;
}

// Return DAC cal constants.
S24XX_API BOOL __stdcall s2426_ReadDacCalConstants( HSESSION sess, S24XXERR *err, s32 *scalar, s32 *offset )
{
	if ( ReadCalConst( sess, err, 0, scalar ) )			// Fetch quadlet 0 (scalar) from cal constant image array in ram.
		if ( ReadCalConst( sess, err, 1, offset ) )		// Fetch quadlet 1 (offset) from cal constant image array in ram.
			return TRUE;	// success

	return FALSE;			// error
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////  ADC  /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


// ADC constants.
#define ADC_NUM_APPCHANS	6		// Number of application channels.
#define ADC_REFCHAN_5V		6		// +5 volt reference channel number.
#define ADC_REFCHAN_0V		7		// 0 volt reference channel number.

#define ADC_RSPSIZE_NO_TS	( 8 * 8 - 2 )
#define ADC_RSPSIZE_TS		( 8 * 19 - 2 )


///////////////////////////////////////////////////////////////////////
// Fetch adc data and timestamp from all eight analog input channels.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadAdc( HSESSION sess, S24XXERR *err, S2426_ADC_SAMPLE *sample, BOOL getTimestamps )
{
	int		chan;
	char	rsp[ADC_RSPSIZE_TS + 5];	// size for largest reply (with timestamps)
	short	ref5V;
	short	ref0V;
	double	factor;

	// Build and execute command, convert samples from cleartext to numeric.
	if ( getTimestamps )
	{
		if ( SessionExecCmd( sess, err, 2426, "rai -t\r\n", ADC_RSPSIZE_TS, rsp ) != FALSE )
		{
			if ( sscanf( rsp, "%hx%x%hx%x%hx%x%hx%x%hx%x%hx%x%hx%x%hx%x",
						&sample[0].data, &sample[0].timestamp,
						&sample[1].data, &sample[1].timestamp,
						&sample[2].data, &sample[2].timestamp,
						&sample[3].data, &sample[3].timestamp,
						&sample[4].data, &sample[4].timestamp,
						&sample[5].data, &sample[5].timestamp,
						&sample[6].data, &sample[6].timestamp,
						&sample[7].data, &sample[7].timestamp ) != 16 )

				*err = ERR_RSPSIZE;
		}
	}
	else if ( SessionExecCmd( sess, err, 2426, "rai\r\n", ADC_RSPSIZE_NO_TS, rsp ) != FALSE )
	{
		if ( sscanf( rsp, "%hx%hx%hx%hx%hx%hx%hx%hx", &sample[0].data, &sample[1].data, &sample[2].data, &sample[3].data, &sample[4].data, &sample[5].data, &sample[6].data, &sample[7].data ) != 8 )
			*err = ERR_RSPSIZE;
	}

	if ( *err != ERR_NONE )
		return FALSE;
	
	// Set fixed voltage values for reference channels.
	sample[ADC_REFCHAN_5V].volts = 5.0;
	sample[ADC_REFCHAN_0V].volts = 0.0;

	// Cache reference sample values.
	ref5V = sample[ADC_REFCHAN_5V].data;
	ref0V = sample[ADC_REFCHAN_0V].data;
	factor = 5.0 / (double)( ref5V - ref0V );

	// Compute voltage corresponding to each raw sample value.
	for ( chan = 0; chan < ADC_NUM_APPCHANS; chan++, sample++ )
		sample->volts = factor * (double)( sample->data - ref0V );

	// Success.
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////  ENCODER  ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
// Return encoder counts.
//	counts		- buffer that will receive counts value.
//	timestamp	- buffer that will receive timestamp value. Set to NULL if timestamp not needed.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadEncoderCounts( HSESSION sess, S24XXERR *err, u32 *counts, u32 *timestamp )
{
	char rsp[50];
	BOOL rtnval;

	// Execute command and convert count (or count/timestamp) from cleartext to numeric.
	if ( timestamp != NULL )
	{
		if ( ( rtnval = SessionExecCmd( sess, err, 2426, "renc -t\r\n", 21, rsp ) ) != FALSE )
			sscanf( rsp, "%x %x", (uint*)counts, (uint*)timestamp );
	}
	else if ( ( rtnval = SessionExecCmd( sess, err, 2426, "renc\r\n", 10, rsp ) ) != FALSE )
		sscanf( rsp, "%x", (uint*)counts );

	// Success.
	return rtnval;
}

/////////////////////////////////////////////////
// Return encoder preload register.
//	counts		- buffer that will receive counts value
//	timestamp	- buffer that will receive timestamp value
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_ReadEncoderPreload( HSESSION sess, S24XXERR *err, u32 *preload )
{
	char rsp[50];
	BOOL rtnval;

	// Execute command and convert preload from cleartext to numeric.
	if ( ( rtnval = SessionExecCmd( sess, err, 2426, "rpre\r\n", 10, rsp ) ) != FALSE )
		sscanf( rsp, "%x", (uint*)preload );

	return rtnval;
}

/////////////////////////////////////////////
// Program encoder preload register.
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_WriteEncoderPreload( HSESSION sess, S24XXERR *err, u32 preload )
{
	char cmd[20];	// command buffer

	// Build and execute command.
	sprintf( cmd, "wpre 0x%x\r\n", (uint)preload );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}

/////////////////////////////////////////////////////////////////////////////
// Program encoder interface operating mode.
// Imports:
//	clockMode		- NONQUADRATURE | QUADRATURE_X1 | QUADRATURE_X2 | QUADRATURE_X4
//	preloadEnable	- ENABLE | DISABLE
// Returns TRUE upon success, else FALSE.

S24XX_API BOOL __stdcall s2426_WriteEncoderMode( HSESSION sess, S24XXERR *err, S2426_ENC_CLOCKMODE clockMode, S2426_ENC_PRELOADENABLE preloadEnable )
{
	char cmd[20];	// command buffer
	char *ckmode;
	char *plmode;

	// Select clock mode string.
	switch ( clockMode )
	{
	case NONQUADRATURE:	ckmode = "nq";	break;
	case QUADRATURE_X1:	ckmode = "q1";	break;
	case QUADRATURE_X2:	ckmode = "q2";	break;
	case QUADRATURE_X4:	ckmode = "q4";	break;
	default: *err = ERR_CMDARG;	return FALSE;
	}

	// Select preload enable string.
	switch ( preloadEnable )
	{
	case ENC_PRELOAD_ENABLE:	plmode = "on";	break;
	case ENC_PRELOAD_DISABLE:	plmode = "off";	break;
	default: *err = ERR_CMDARG;	return FALSE;
	}

	// Build and execute command.
	sprintf( cmd, "wem %s %s\r\n", ckmode, plmode );
	return SessionExecCmd( sess, err, 2426, cmd, 0, NULL );
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////  COMPORT  ////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// Open comport.
// Imports:
//	baudrate	- any standard bit rate up to 115200
//	parity		- PARITY_TYPE_NONE | PARITY_TYPE_ODD | PARITY_TYPE_EVEN
//	databits	- NDATABITS_5 | NDATABITS_6 | NDATABITS_7 | NDATABITS_8
//	stopbits	- NSTOPBITS_1 | NSTOPBITS_2
//	rxCallback	- callback function that handles incoming chars from comport

S24XX_API BOOL __stdcall s2426_ComportOpen( HSESSION sess, S24XXERR *err, u32 baudrate, S2426_PARITY parity, S2426_DATABITS databits, S2426_STOPBITS stopbits )
{
	char parchar;

	// Validate baudrate, stopbits and databits.
	if ( ( baudrate > 115200 ) || ( (uint)stopbits > 2 ) || ( (uint)databits < NDATABITS_5 ) || ( (uint)databits > NDATABITS_8 ) )
	{
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Validate parity type and convert to char.
	switch ( parity )
	{
	case PARITY_TYPE_NONE:	parchar = 'n';	break;
	case PARITY_TYPE_ODD:	parchar = 'o';	break;
	case PARITY_TYPE_EVEN:	parchar = 'e';	break;
	default:
		*err = ERR_CMDARG;
		return FALSE;
	}

	// Attach comport to this session. Return TRUE if successful.
	return SessionComportOpen( sess, err, baudrate, parchar, (u8)databits, (u8)stopbits );
}

////////////////////////////////////////////////////////////////////////
// Close comport.

S24XX_API BOOL __stdcall s2426_ComportClose( HSESSION sess, S24XXERR *err )
{
	return SessionComportClose( sess, err );
}

///////////////////////////////////////////////////////////////
// Read data from the comport.
// Returns:
//	nbytes if successful.
//	0 if connection timed out or closed.
//	~0 if linestate changed, with result stored in buf[0].

S24XX_API int __stdcall s2426_ComportRead( HSESSION sess, S24XXERR *err, void *buf, int len, BOOL wait )
{
	return SessionComportRead( sess, err, (u8 *)buf, len, wait );
}

///////////////////////////////////////////////////////////////
// Write data to the comport.
// Returns number of bytes sent.

S24XX_API int __stdcall s2426_ComportWrite( HSESSION sess, S24XXERR *err, void *buf, int len, BOOL wait )
{
	return SessionComportWrite( sess, err, (u8 *)buf, len, wait );
}

//////////////////////////////////////////////////////////////
// Execute comport control command.

S24XX_API BOOL __stdcall s2426_ComportIoctl( HSESSION sess, S24XXERR *err, COMPORT_IOCTL ioctl, void *val )
{
	return SessionComportIoctl( sess, err, ioctl, val );
}
