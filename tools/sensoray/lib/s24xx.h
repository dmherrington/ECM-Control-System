////////////////////////////////////////////////////////////////////////////
// Module    : s24xx.h
// Function  : Top-level api header for middleware and applications
// Copyright : (C) 2010 Sensoray
////////////////////////////////////////////////////////////////////////////


// Note: one of these external symbols must be defined:
//  OSTYPE_WINDOWS
//  OSTYPE_LINUX


#ifndef _S24XX_H_
#define _S24XX_H_

// Windows: Export/import dll functions
#if defined (OSTYPE_WINDOWS)

#if defined (S24XX_EXPORTS)
#define S24XX_API __declspec(dllexport)
#else
#define S24XX_API __declspec(dllimport)
#endif

// Linux: No special treatment for lib functions
#elif defined (OSTYPE_LINUX)
#define S24XX_API
#define __stdcall

#else
#error "must define OSTYPE_ type"
#endif


#include "stypes.h"

#ifndef HSESSION_DEFINED
typedef void *HSESSION;							// Handle to session.
#define HSESSION_DEFINED
#endif

// GENERIC /////////////////////////////////////////////////////////////////////////////////////////////////

// Enumerated types -----------------------

// Telnet timeout units.
typedef enum S24XX_TOUT_UNITS_ENUM { UNITS_MILLISECONDS, UNITS_SECONDS } S24XX_TOUT_UNITS;

// Action in response to telnet timeout.
typedef enum S24XX_TOUT_RESPONSE_ENUM { ACTION_NONE, ACTION_RESET } S24XX_TOUT_RESPONSE;

// Comport ioctl codes.
typedef enum COMPORT_IOCTL {
	BAUDRATE,		// Set/get baudrate.
	PARITY,			// Set/get parity.
	DATABITS,		// Set/get databits.
	STOPBITS,		// Set/get stopbits.
	TXBREAKON,		// Begin transmit break.
	TXBREAKOFF,		// End transmit break.
	RXFLUSH			// Flush receive pipeline.
} COMPORT_IOCTL;

// Types -----------------------------

// Callback for updating progress during firmware updates to flash.
typedef void (* PROGRESS_CALLBACK)( u32 nbytes );


// 2410 /////////////////////////////////////////////////////////////////////////////////////////////////

// Message type codes for asynchronous event notification messages:
#define CAPMSG_ATTACH			'a'					// 'a'			- registered callback
#define CAPMSG_DETACH			'q'					// 'q'			- unregistered callback
#define CAPMSG_NACK				'n'					// 'n'			- async capture command NACK
#define CAPMSG_ERROR			'e'					// 'e'			- async capture command error
#define CAPMSG_TIMER			't'					// 'tNNNN'		- start capture inactivity timer and set it to timeout in NNNN milliseconds
#define CAPMSG_POLARITY			'p'					// 'pNNNNNN'	- set polarity (NNNNNN = 48-bit binary data)
#define CAPMSG_CONTINUOUS		'c'					// 'cNNNNNN'	- enable continuous capture (NNNNNN = 48-bit binary mask)
#define CAPMSG_ONESHOT			'o'					// 'oNNNNNN'	- enable one-shot capture (NNNNNN = 48-bit binary mask)
#define CAPMSG_DISABLE			'd'					// 'dNNNNNN'	- disable capture (NNNNNN = 48-bit binary mask)
#define CAPMSG_EVENT			'v'					// 'vNNNNNN'	- capture event (NNNNNN = 48-bit binary data)

// Types ---------------------------

// Digital output operating mode.
typedef enum S2410_DOUT_MODE_ENUM { DOUT2410_MODE_STANDARD, DOUT2410_MODE_PWM } S2410_DOUT_MODE;

// Handle to async event notification system.
typedef void *HEVCAP;

// Application event callback prototype:
//	msgtype	- notification message type code.
//	val		- pointer to array of u16 values.
typedef void (*EVENT_CBK)( char msgtype, const u16 *val );

// 2426 /////////////////////////////////////////////////////////////////////////////////////////////////

// Manifest constants ---------------------

#define S2426_NUM_ADC_CHANS		8

// Comport settings ---------

#define COMPORT_PARITY_NONE		1
#define COMPORT_PARITY_ODD		2
#define COMPORT_PARITY_EVEN		3
#define COMPORT_PARITY_MARK		4
#define COMPORT_PARITY_SPACE	5

#define COMPORT_STOP_1			1
#define COMPORT_STOP_2			2
#define COMPORT_STOP_1_5		3

// Flow Control mask options
#define COMPORT_OXON			4		// Output flow control - start/stop sending on XON/XOFF
#define COMPORT_IXON			8		// Input flow control - send XON/XOFF to start/stop receiving

// Line state notification flags
#define COMPORT_BREAK_ERROR		16		// Break-detect Error
#define COMPORT_FRAMING_ERROR	8		// Framing Error
#define COMPORT_PARITY_ERROR	4		// Parity Error
#define COMPORT_OVERRUN_ERROR	2		// Overrun Error

// Enumerated types -----------------------

// Digital output operating mode.
typedef enum S2426_DOUT_MODE_ENUM { DOUT2426_MODE_STANDARD, DOUT2426_MODE_PWM } S2426_DOUT_MODE;

// Encoder clock mode.
typedef enum S2426_ENC_CLOCKMODE_ENUM { NONQUADRATURE, QUADRATURE_X1, QUADRATURE_X2, QUADRATURE_X4 } S2426_ENC_CLOCKMODE;

// Encoder preload enable.
typedef enum S2426_ENC_PRELOADENABLE_ENUM { ENC_PRELOAD_DISABLE, ENC_PRELOAD_ENABLE } S2426_ENC_PRELOADENABLE;

// Comport parity type.
typedef enum S2426_PARITY_ENUM { PARITY_TYPE_NONE, PARITY_TYPE_ODD, PARITY_TYPE_EVEN } S2426_PARITY;

// Comport char bit count.
typedef enum S2426_DATABITS_ENUM { NDATABITS_5 = 5, NDATABITS_6 = 6, NDATABITS_7 = 7, NDATABITS_8 = 8 } S2426_DATABITS;

// Comport stop bit count.
typedef enum S2426_STOPBITS_ENUM { STOPBITS_0, STOPBITS_1 } S2426_STOPBITS;


// Types -----------------------------

// Analog input snapshot. Note that s2426_ReadAdc() fills an array of eight of these.
typedef struct S2426_ADC_SAMPLE {
	s16		data;			// Uncorrected (raw) analog in data.
	uint	timestamp;		// Time at which sample was acquired.
	double	volts;			// Corrected analog in data.
} S2426_ADC_SAMPLE;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////  FUNCTION PROTOTYPES  /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef __cplusplus
extern "C" {
#endif


// Generic --------------------

// API/session management.
S24XX_API BOOL		__stdcall s24xx_ApiOpen				( void );
S24XX_API void		__stdcall s24xx_ApiClose			( void );
S24XX_API BOOL		__stdcall s24xx_SessionOpen			( HSESSION *psess, S24XXERR *err, u16 svrModel, const char *ipaddr, u16 port, u32 msec );
S24XX_API void		__stdcall s24xx_SessionClose		( HSESSION sess );
S24XX_API BOOL		__stdcall s24xx_Reboot				( HSESSION sess, S24XXERR *err, BOOL configmode );
S24XX_API BOOL		__stdcall s24xx_ResetIo				( HSESSION sess, S24XXERR *err );
S24XX_API BOOL		__stdcall s24xx_GetVersionInfo		( HSESSION sess, S24XXERR *err, char *buf, u32 bufsize, BOOL *isSecondaryFw );
S24XX_API const char * __stdcall s24xx_ErrorText		( S24XXERR err );

// Firmware access.
S24XX_API BOOL		__stdcall s24xx_FirmwareWriteEnable	( HSESSION sess, S24XXERR *err );
S24XX_API BOOL		__stdcall s24xx_FirmwareErase		( HSESSION sess, S24XXERR *err );
S24XX_API BOOL		__stdcall s24xx_FirmwareUpload		( HSESSION sess, S24XXERR *err, u32 flashaddr, u8 *buf, u32 nbytes, PROGRESS_CALLBACK ProgressCallback, u32 CallbackFreq );
S24XX_API BOOL		__stdcall s24xx_FirmwareActivate	( HSESSION sess, S24XXERR *err );

// Time.
S24XX_API BOOL		__stdcall s24xx_SetTimeout			( HSESSION sess, S24XXERR *err, u32 timeout, S24XX_TOUT_UNITS seconds, S24XX_TOUT_RESPONSE reset );
S24XX_API BOOL		__stdcall s24xx_ReadTimestamp		( HSESSION sess, S24XXERR *err, u32 *time );
S24XX_API BOOL		__stdcall s24xx_WriteTimestamp		( HSESSION sess, S24XXERR *err, u32 time );


// 2410 --------------------

// Digital I/O commands.
S24XX_API BOOL		__stdcall s2410_WriteDout			( HSESSION sess, S24XXERR *err, u16 *states );
S24XX_API BOOL		__stdcall s2410_ReadDout			( HSESSION sess, S24XXERR *err, u16 *states );
S24XX_API BOOL		__stdcall s2410_ReadDin				( HSESSION sess, S24XXERR *err, u16 *states );
S24XX_API BOOL		__stdcall s2410_SetDebounceTime		( HSESSION sess, S24XXERR *err, u8 chan, u8 msec );
S24XX_API BOOL		__stdcall s2410_SetDoutMode			( HSESSION sess, S24XXERR *err, u8 chan, S2410_DOUT_MODE pwmMode );
S24XX_API BOOL		__stdcall s2410_WritePwm			( HSESSION sess, S24XXERR *err, u8 chan, u16 ontime, u16 offtime );

// Event capture commands.
S24XX_API BOOL		__stdcall s2410_ReadCapFlags		( HSESSION sess, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_WriteCapPolarity	( HSESSION sess, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_WriteCapDisable		( HSESSION sess, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_WriteCapContinuous	( HSESSION sess, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_WriteCapOneshot		( HSESSION sess, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_WriteCapTimer		( HSESSION sess, S24XXERR *err, u16 msec );

// Asynchronous event capture.
S24XX_API HEVCAP	__stdcall s2410_AsyncCapBegin		( const char *ipaddr, S24XXERR *err, u16 port, EVENT_CBK callback, u32 msec );
S24XX_API BOOL		__stdcall s2410_AsyncCapEnd			( HEVCAP client, S24XXERR *err );
S24XX_API BOOL		__stdcall s2410_AsyncCapStartTimer	( HEVCAP EventHandler, S24XXERR *err, u16 msec );
S24XX_API BOOL		__stdcall s2410_AsyncCapDisable		( HEVCAP EventHandler, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_AsyncCapContinuous	( HEVCAP EventHandler, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_AsyncCapOneshot		( HEVCAP EventHandler, S24XXERR *err, u16 *flags );
S24XX_API BOOL		__stdcall s2410_AsyncCapPolarity	( HEVCAP EventHandler, S24XXERR *err, u16 *flags );

// Other.
S24XX_API BOOL		__stdcall s2410_SetLedBrightness	( HSESSION sess, S24XXERR *err, uint intensity );

// 2426 --------------------

// Digital i/o.
S24XX_API BOOL		__stdcall s2426_WriteDout			( HSESSION sess, S24XXERR *err, u16 states );
S24XX_API BOOL		__stdcall s2426_ReadDout			( HSESSION sess, S24XXERR *err, u16 *states );
S24XX_API BOOL		__stdcall s2426_ReadDin				( HSESSION sess, S24XXERR *err, u8 *states, u32 *timestamp );
S24XX_API BOOL		__stdcall s2426_SetDebounceTime		( HSESSION sess, S24XXERR *err, u8 chan, u8 msec );
S24XX_API BOOL		__stdcall s2426_SetDoutMode			( HSESSION sess, S24XXERR *err, u8 chan, S2426_DOUT_MODE pwmMode );
S24XX_API BOOL		__stdcall s2426_WritePwm			( HSESSION sess, S24XXERR *err, u8 chan, u16 ontime, u16 offtime );

// Analog i/o.
S24XX_API BOOL		__stdcall s2426_WriteAout			( HSESSION sess, S24XXERR *err, s16 setpoint, BOOL calCorrect );
S24XX_API BOOL		__stdcall s2426_ReadAout			( HSESSION sess, S24XXERR *err, s16 *setpoint );
S24XX_API BOOL		__stdcall s2426_ReadAdc				( HSESSION sess, S24XXERR *err, S2426_ADC_SAMPLE *sample, BOOL getTimestamps );
S24XX_API BOOL		__stdcall s2426_AdcLockChan			( HSESSION sess, S24XXERR *err, u8 chan );
S24XX_API BOOL		__stdcall s2426_SetDacCalConstants	( HSESSION sess, S24XXERR *err, s32 scalar, s32 offset );
S24XX_API BOOL		__stdcall s2426_ReadDacCalConstants	( HSESSION sess, S24XXERR *err, s32 *scalar, s32 *offset );

// Encoder.
S24XX_API BOOL		__stdcall s2426_ReadEncoderCounts	( HSESSION sess, S24XXERR *err, u32 *counts, u32 *timestamp );
S24XX_API BOOL		__stdcall s2426_ReadEncoderPreload	( HSESSION sess, S24XXERR *err, u32 *preload );
S24XX_API BOOL		__stdcall s2426_WriteEncoderPreload	( HSESSION sess, S24XXERR *err, u32 preload );
S24XX_API BOOL		__stdcall s2426_WriteEncoderMode	( HSESSION sess, S24XXERR *err, S2426_ENC_CLOCKMODE clockMode, S2426_ENC_PRELOADENABLE preloadEnable );

// Comport.
S24XX_API BOOL		__stdcall s2426_ComportOpen			( HSESSION sess, S24XXERR *err, u32 baudrate, S2426_PARITY parity, S2426_DATABITS databits, S2426_STOPBITS stopbits );
S24XX_API BOOL		__stdcall s2426_ComportClose		( HSESSION sess, S24XXERR *err );
S24XX_API int		__stdcall s2426_ComportRead			( HSESSION sess, S24XXERR *err, void *buf, int len, BOOL wait );
S24XX_API int		__stdcall s2426_ComportWrite		( HSESSION sess, S24XXERR *err, void *buf, int len, BOOL wait );
S24XX_API BOOL		__stdcall s2426_ComportIoctl		( HSESSION sess, S24XXERR *err, COMPORT_IOCTL ioctl, void *val );


#ifdef __cplusplus
}
#endif


#endif	// _S24XX_H_
