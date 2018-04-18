#ifndef _STYPES_H_
#define _STYPES_H_

// Types.

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef signed short	s16;
typedef unsigned long	u32;
typedef signed long		s32;
typedef int				BOOL;
typedef unsigned int	uint;

// Constants.

#ifndef TRUE
#define TRUE			1
#endif

#ifndef FALSE
#define FALSE			0
#endif

#ifndef NULL
#define NULL			0
#endif

// API error codes.
typedef enum S24XXERR {
	ERR_NONE				= 0,		// No problems.
	// Initialization errors:
	ERR_MALLOC				= -1,		// Can't allocate memory.
	ERR_SOCKETCREATE		= -2,		// Can't create socket.
	ERR_SESSIONCONNECT		= -3,		// Can't connect to server.
	ERR_TOOMANYSESSIONS		= -4,		// Server already running maximum number of connections.
	ERR_OPENSHELL			= -6,		// Failed to receive shell signon message.
	ERR_THREADCREATE		= -7,		// Can't create thread.
	ERR_CRITSECTCREATE		= -8,		// Can't create critical section.
	ERR_CREATEMUTEX			= -9,		// Can't create mutex.
	// Fatal (unrecoverable) run-time errors:
	ERR_INVALIDSESSION		= -100,		// Invalid session handle.
	ERR_SOCKET				= -101,		// Socket error (e.g., argument error, failed network subsystem).
	ERR_CONNCLOSED			= -102,		// Connection was closed.
	ERR_NETWORKWRITE		= -103,		// Socket write failed.
	ERR_TIMEOUT				= -104,		// Response timeout.
	// Non-fatal (recoverable) run-time errors:
	ERR_COMPORTATTACH		= -200,		// Session could not be attached to Comport. 
	ERR_SHELLCOMMAND		= -201,		// Shell command not available on registered I/O server.
	ERR_RSPSIZE				= -202,		// Unexpected command response size.
	ERR_CMDARG				= -203,		// Invalid command argument.
	ERR_BUFWOULDOVERFLOW	= -204,		// Operation would overflow buffer.
	ERR_COMPORTWASATTACHED	= -205,		// Comport was attached and app tried to attach it again or execute non-comport transaction.
	ERR_COMPORTUNATTACHED	= -206		// Comport not attached and app tried to execute comport transaction.
} S24XXERR;


#endif // _STYPES_H_
