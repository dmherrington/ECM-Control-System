///////////////////////////////////////////////////////////////////////////////////////
// File			: session.h
// Function		: Include file for applications using Sensoray model 24xx I/O servers
// Author		: Jim Lamberson
// Created		: 2008/05/19
// Copyright	: Copyright (C) 2008 Sensoray
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _SESSION_H_
#define _SESSION_H_

// Types.
#include "stypes.h"

#ifndef HSESSION_DEFINED
typedef void *HSESSION;		// Handle to session.
#define HSESSION_DEFINED
#endif

#define IGNORE_EXPECTEDRSPSIZE		(~0)		// tell SessionExecCmd to ignore response


// API functions --------------------------------

BOOL		SessionApiOpen			( void );																				// Open the api.
void		SessionApiClose			( void );																				// Close api.
S24XXERR	SessionOpen				( HSESSION *psess, S24XXERR *err, u16 svrModel, const char *ipaddr, u16 port, u32 msec, u32 logsize );	// Create session, open telnet connection and logon to remote shell.
void		SessionClose			( HSESSION sess );																		// Close shell and its connection.

BOOL		SessionLogEnable		( HSESSION sess, BOOL enable );															// Turn on/off debug logging.
char		*ShellCommandExec		( HSESSION sess, S24XXERR *err, const char* cmd, BOOL requirePrompt );					// Issue command string, return pointer to response string.
int			SessionStreamRead		( HSESSION sess, S24XXERR *err, char *buf, int bufsize, BOOL wait );					// Fetch stream data from server.
char		*SessionReadUntilPrompt	( HSESSION sess, S24XXERR *err, BOOL requirePrompt );									// Fetch asciiz data from server until '>' prompt detected.
BOOL		SessionRawWrite			( HSESSION sess, const char* buf, int len );											// Send unfiltered data to server. May be stream data or telnet commands.
int			SessionStreamWrite		( HSESSION sess, S24XXERR *err, const char* buf, int nbytes, BOOL wait );				// Send stream data to TxSerializerThread for transmission to server.
BOOL		SessionExecCmd			( HSESSION sess, S24XXERR *err, u16 model, const char *cmd, int expectedRspSize, char *rsp );	// Execute shell command, return response.

BOOL		SessionComportOpen		( HSESSION sess, S24XXERR *err, u32 baud, char parity, u8 databits, u8 stopbits );		// Open comport connection.
BOOL		SessionComportClose		( HSESSION sess, S24XXERR *err );														// Close comport connection.
int			SessionComportRead		( HSESSION sess, S24XXERR *err, u8 *data, int len, BOOL wait );							// Read from comport connection. 
int			SessionComportWrite		( HSESSION sess, S24XXERR *err, u8 *data, int len, BOOL wait );							// Write to comport connection.
BOOL		SessionComportIoctl		( HSESSION sess, S24XXERR *err, COMPORT_IOCTL ioctl, void *val );						// Set config and return programmed value. Specify 0 to return current value.
 
S24XXERR	SessionError			( HSESSION sess );																		// Return last error.
void		SessionErrorClear		( HSESSION sess );																		// Clear last error.
void		SessionErrorAssert		( HSESSION sess, S24XXERR err );														// Assert last error.

u32			SessionLogCopy			( HSESSION sess, u8 *buf, u32 bufsize );												// Copy session log to application buffer.
void		SessionLogPrint			( HSESSION sess, u32 maxchars );														// Print session log to stdout.


#endif // _SESSION_H_
