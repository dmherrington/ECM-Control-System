////////////////////////////////////////////////////////////////////////////////
// File			: session.c
// Function		: Public API for Sensoray model 24xx I/O server
// Target		: OS-independent
// Author		: Jim Lamberson
// Created		: 2008/05/14
// Copyright	: Copyright (C) 2008 Sensoray
////////////////////////////////////////////////////////////////////////////////


#define S24XX_EXPORTS




// The app views sessions as void pointers, but this module knows they are actually pointers to session objects.
typedef struct SESSION_STRUCT *HSESSION;	// Define HSESSION as object pointer so that prototypes in session.h will match this implementation.
#define HSESSION_DEFINED

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "osi_wrapper.h"
#include "s24xx.h"
#include "session.h"


// Configuration constants ------------------------------------------------------------------

#define NUM_RXMSG_OBJECTS				50
#define RXMSGPOOL_HIWATER				40
#define RXMSGPOOL_LOWATER				10

#define NUM_TXMSG_NONSTREAM_OBJECTS		50

#define SESSION_BUFSIZE 				1000		// Size of internal shell command response buffer.


// Manifest constants -----------------------------------------------------------------------

// Telnet commands (rfc854).
#define SE						((const char)240)		// End of subnegotiation parameters.
#define NOP						((const char)241)		// No operation.
#define DM						((const char)242)		// The data stream portion of a Synch.
#define BRK						((const char)243)		// NVT character BRK (Break).
#define IP						((const char)244)		// Interrupt Process.
#define AO						((const char)245)		// Abort Output.
#define AYT						((const char)246)		// Are You There?
#define EC						((const char)247)		// Erase Character.
#define EL						((const char)248)		// Erase Line.
#define GA						((const char)249)		// Go Ahead.
#define SB						((const char)250)		// Indicates that what follows is subnegotiation of the indicated option.
#define WILL					((const char)251)		// Indicates desire to begin performing, or confirmation that we are now performing, the indicated option.
#define WONT					((const char)252)		// Refusal to perform, or continue performing, the indicated option.
#define DO						((const char)253)		// Request that the other party perform, or confirmation that we are expecting the other party to perform, the indicated option.
#define DONT					((const char)254)		// Demand that the other party stop performing, or confirmation that we are no longer expecting the other party to perform, the indicated option.
#define IAC						((const char)255)		// Interpret As Command.

// Telnet options.
#define TELOPT_BINARY			0				// Binary transmission (rfc 856).
#define TELOPT_ECHO				1				// Echo (rfc 857).
#define	TELOPT_SGA				3				// Suppress GoAheads (rfc 858).
#define TELOPT_CPC				44				// Com Port Control (rfc 2217)

// Com Port Control (CPC) Options.
#define CPC_SIGNATURE			0
#define CPC_BAUDRATE			1				// Baud rate.
#define CPC_DATABITS			2				// Word size in bits.
#define CPC_PARITY				3				// Parity type.
#define CPC_STOPBITS			4				// Number of stop bits per word.
#define CPC_CONTROL				5				// Behavior control (e.g., tx break, flow control).
#define CPC_NOTIFY_LINE			6				// Line state change notification.
#define CPC_NOTIFY_MODEM		7				// Modem control change notification.
#define CPC_FLOW_SUSPEND		8				// Pause tx stream.
#define CPC_FLOW_RESUME			9				// Resume tx stream.
#define CPC_MASK_LINE			10				// Line state change event mask.
#define CPC_MASK_MODEM			11				// Modem state change event mask.
#define CPC_PURGE_DATA			12				// Purge rx, tx or both.

// CPC option replies.
#define CPC_REPLY(CMD)			( CMD + 100 )	// Reply to comport configuration command CMD (e.g., CPC_BAUDRATE).

// CPC linestate change flags.
#define CPC_BREAK_DETECT		16
#define CPC_FRAMING_ERROR		8
#define CPC_PARITY_ERROR		4
#define CPC_OVERRUN_ERROR		2

// CPC_CONTROL settings ---------------
												// Flow control for outbound/both:
#define CPC_OUTFLOW_GET			0				//   Return current flow control.
#define CPC_OUTFLOW_USE_NONE	1				//   Use no flow control.
#define CPC_OUTFLOW_USE_XON		2				//   Use xon/xoff.
#define CPC_OUTFLOW_USE_HW		3				//   Use hardware flow control (unsupported).
												// Transmit break:
#define CPC_BREAK_GET			4				//   Return current state.
#define CPC_BREAK_SET_ON		5				//   Start.
#define CPC_BREAK_SET_OFF		6				//   Stop.
												// DTR control (unsupported):
#define CPC_DTR_GET				7				//   Return current state.
#define CPC_DTR_SET_ON			8				//   Assert.
#define CPC_DTR_SET_OFF			9				//   Negate.
												// RTS control (unsupported):
#define CPC_RTS_GET				10				//   Return current state.
#define CPC_RTS_SET_ON			11				//   Assert.
#define CPC_RTS_SET_OFF			12				//   Negate.
												// Flow control for inbound:
#define CPC_INFLOW_GET			13				//   Return current flow control.
#define CPC_INFLOW_USE_NONE		14				//   Use no flow control.
#define CPC_INFLOW_USE_XON		15				//   Use xon/xoff.
#define CPC_INFLOW_USE_HW		16				//   Use hardware flow control (unsupported).
												// Hardware flow control options (unsupported):
#define CPC_OUTFLOW_USE_DCD		17				//   Use DCD.
#define CPC_INFLOW_USE_DTR		18				//   Use DTR.
#define CPC_OUTFLOW_USE_DSR		19				//   Use DSR.

#define	LFLOW_OFF				0		// Disable remote flow control.
#define	LFLOW_ON				1		// Enable remote flow control.
#define	LFLOW_RESTART_ANY		2		// Restart output on any char.
#define	LFLOW_RESTART_XON		3		// Restart output only on XON.

// Constants for socketRecv().
#define RECV_OOB				TRUE	// Read out-of-band data.
#define RECV_INBAND				FALSE	// Read in-band stream data.

// Priority levels for ordering of MSG objects in linked lists.
#define MSG_PRIORITY_NORMAL		0
#define MSG_PRIORITY_HIGH		1


// Macros -----------------------------------------------------

#define MIN(a,b)		( ((a)<(b)) ? (a) : (b) )


// Types ------------------------------------------------------

typedef enum MSGTYPE {				// MSG TYPES ------------
	MSGTYPE_STREAM,					//  Stream data.
	MSGTYPE_TELNET_COMMAND,			//  Complete telnet command.
	MSGTYPE_TELNET_BRK,				//  Telnet BRK (received) -- no actual telnet command in MSG data buffer.
	MSGTYPE_CPC_SUBCOMMAND,			//  CPC subcommand, with leading IAC SB CPC and trailing IAC SE stripped from telnet command.
	MSGTYPE_RXPOOL_LOWATER,			//  Notification that pool level just dropped to low water mark.
	MSGTYPE_RXPOOL_HIWATER			//  Notification that pool level just rose to high water mark.
} MSGTYPE;

typedef enum MSGSET_TYPE_ENUM {		// MSG COLLECTION TYPE ------------
	MSGSET_TYPE_FIFO,				//  Fifo.
	MSGSET_TYPE_POOL				//  Free object pool.
} MSGSET_TYPE;

// Forward declarations.
typedef struct SESSION_STRUCT	SESSION;
typedef struct MSGSET_STRUCT	MSGSET;
typedef struct MSG_STRUCT		MSG;

// Handler for low/high fifo watermarks.
typedef void (*WATERMARK_HANDLER)( SESSION *sess, BOOL isHighMark );

typedef struct MSG_STRUCT {					// MSG OBJECT ---------------------
	MSG				*next;					// Link to next item in list. NULL if this is last item in list. *** REQUIRED TO BE FIRST MEMBER ***
	uint			priority;				// List priority. Standard priority is zero.
	MSGSET			*owner;					// Pool that owns this object.
	MSGTYPE			type;					// Message type classification.
	uint			rdIndex;				// NextRead index in payload buffer.
	u16				len;					// Byte count in payload buffer.
	u8				data[256];				// The payload buffer.
} MSG_STRUCT;

typedef struct MSGSET_STRUCT {				// INTERPROCESS MSG EXCHANGE ----------------
	MSG					*list;				//  Pointer to first MSG in linked list of MSG objects. NULL if list is empty.
	MSGSET_TYPE			type;				//  Collection type: FIFO | POOL.
	SESSION				*sess;				//  Session to which this fifo/pool belongs.
	SEMAPHORE			semaphore;			//  NULL if semaphore not needed to signal level change.
	CRITSECT			cs;					//  Critical section used to guarantee atomic access.
	uint				hiwater;			//  High water mark.
	uint				lowater;			//  Low water mark.
	WATERMARK_HANDLER	watermarkHandler;	//  High water handler. Set to NULL if not used.
} MSGSET_STRUCT;

#define SESSION_SIGNATURE_VALID		0xDAD0
#define SESSION_SIGNATURE_INVALID	0x0000

typedef struct SESSION_STRUCT {				// SESSION STATE ---------------------
											// Connectivity:
	u32				signature;				//  Indicates session object exists when equal to SESSION_SIGNATURE_VALID.
	u16				svrModel;				//  I/O server model number.
	SOCKET			socket;					//  Handle of socket to which this session is attached. NULL if no socket attached.
	BOOL			isLoggedIn;				//  Logged in and sync'd to remote shell.
	S24XXERR		LastError;				//  Logged error. Only fatal runtime errors are logged; all others are just returned to API clients.
	BOOL			ComportAttached;		//  Comport is attached to this session.
											// Telnet:
	BOOL			RxBinaryMode;			//  Receiver operating in binary mode.
	BOOL			TxBinaryMode;			//  Transmitter operating in binary mode.
	BOOL			EchoEnable;				//  Server echo enabled.
	BOOL			CpcEnable;				//  Com Port Control telnet option has been negotiated.
											// Private threads:
	BOOL			TelnetTerminateSignal;	//  Signals termination request to threads.
	THREAD			RxPacketizerThread;		//  Thread that receives socket data and parses incoming telnet commands.
	THREAD			TxSerializerThread;		//  Thread that serializes and sends socket data and manages tx stream flow control
											// Loose MSG objects:
	MSG				*RxmsgCurrent;			//  MSG currently being filled with incoming rx stream data by RxPacketizerThread.
	MSG				*AppRxmsg;				//  MSG currently being consumed by application rx thread.
											// MSG pools and fifos:
	MSGSET			CtrlMsgPool;			//  Pool of MSG objects available for non-stream messages.
	MSGSET			RxmsgPool;				//  Pool of MSG objects available for rx stream data.
	MSGSET			TxmsgStreamPool;		//  Pool of MSG objects available for tx stream data.
	MSGSET			TxmsgFifo;				//  List of MSG objects to be processed by TxSerializerThread.
	MSGSET			RxmsgFifo;				//  List of MSG objects to be processed by app stream receiver.
	MSGSET			RxCpcReplyFifo;			//  List of MSG objects to be processed by app stream/control transmitter.
											// Rx stream:
	uint			FlushingComportRx;		//  Actively purging our comport rx pipeline if non-zero. Keeps nested count of Purge commands/replies.
	u8				appbuf[SESSION_BUFSIZE];//  Shell command response buffer.
											// Session-wide synchronization objects used to guarantee thread safe operation:
	MUTEX			ReadMutex;				//  Held by app read thread context while waiting for rx data to hold off session destruction during session termination.
	CRITSECT		critsectShell;			//  Only one remote shell command can be in play at a time.
	CRITSECT		critsectTelnet;			//  Only one telnet transaction can be in play at a time.
											// Debug log - captures most recent data sent to/from socket:
	BOOL			logEnable;				//  Enable logging to buffer. Defaults to disabled when session object created.
	u32				logIndex;				//  Next write index.
	u32				logCount;				//  Buffer count.
	u32				logbufSize;				//  Char capacity of log buffer. MUST BE A POWER OF 2.
	u8				*logbuf;				//  The log buffer, which is a ring buffer.
} SESSION_STRUCT;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////  OSD FUNCTION WRAPPERS  //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static BOOL SemaphorePend( SEMAPHORE s, BOOL wait )
{
	return (BOOL)( ( s != NULL ) ? osdSemaphorePend( s, wait ) : FALSE );
}

static void SemaphorePost( SEMAPHORE s )
{
	if ( s != NULL )
		osdSemaphorePost( s );
}

static void SemaphoreDestroy( SEMAPHORE *psem )
{
	if ( *psem != NULL )
	{
		osdSemaphoreDestroy( *psem );
		*psem = NULL;
	}
}

static BOOL MutexPend( MUTEX m, BOOL wait )
{
	return ( m != NULL ) ? osdMutexPend( m, wait ) : FALSE;
}

static void MutexPost( MUTEX m )
{
	if ( m != NULL )
		osdMutexPost( m );
}

static void MutexDestroy( MUTEX *pmutex )
{
	if ( *pmutex != NULL )
	{
		osdMutexDestroy( *pmutex );
		*pmutex = NULL;
	}
}

static void CriticalSectionDestroy( CRITSECT *cs )
{
	if ( *cs != NULL )
	{
		osdCriticalSectionDestroy( *cs );
		*cs = NULL;
	}
}

static void ThreadWaitTerminate( THREAD *t )
{
	if ( *t != NULL )
	{
		osdThreadWaitTerminate( *t );
		*t = NULL;
	}
}

static void SocketDisconnect( SOCKET *s )
{
	if ( *s != INVALID_SOCKET_HANDLE )
	{
		osdSocketDisconnect( *s );
		*s = INVALID_SOCKET_HANDLE;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////  ERROR PROCESSING  /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static BOOL isValidSession( SESSION *sess )
{
	if ( sess != NULL )
		if ( sess->signature == SESSION_SIGNATURE_VALID )
			return TRUE;

	return FALSE;
}

// Return LastError.
int SessionError( SESSION *sess )
{
	return isValidSession( sess ) ? sess->LastError : ERR_INVALIDSESSION;
}

// Set LastError if not already asserted.
void SessionErrorAssert( SESSION *sess, S24XXERR err )
{
	if ( isValidSession( sess ) )
		sess->LastError = err;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////  FIFO & POOL FUNCTIONS  //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Remove first MSG from a list.
// Note: the list must not be modified while this function executes.
// Returns item pointer if list was not empty, else NULL.

void *MsgRemoveListHead( MSG *list[] )
{
	MSG *msg = *list;

	if ( msg != NULL )
	{
		*list = msg->next;
		msg->next = NULL;
	}
	
	return msg;
}

//////////////////////////////////////////////////////
// Return count of msgs in a linked list.
// Note: the list must not be modified while this function executes.

uint MsgListLen( MSG *list )
{
	register uint n = 0;
	register MSG *msg = list;
	
	while ( msg != NULL )
	{
		n++;
		msg = msg->next;
	}

	return n;
}

///////////////////////////////////////////////
// Create a linked list of MSG objects.
// Allocates memory for the objects.
// Imports:
//	nobjects	- number of objects to create.
//	owner		- pool that owns the objects (objects are returned to this pool when released).
// Returns list pointer, or NULL if error.

// Helper: create and init MSG object.
MSG *MsgCreate( MSGSET *owner )
{
	MSG *msg = (MSG *)malloc( sizeof(MSG) );

	if ( msg != NULL )
	{
		msg->next		= NULL;		// not yet chained to a list.
		msg->owner		= owner;	// register owner.
		msg->len		= 0;		// no payload available.
		msg->rdIndex	= 0;
	}

	return msg;
}

/////////////////////////////////////////////////////////////////////
// Destroy a linked list of MSG objects and free their resources.
// The list pointer is set to NULL before returning to indicate empty list.

void DestroyMsgChain( MSG **chain )
{
	MSG *msg = *chain;		// Init pointer to first MSG in list, if there is one.

	while ( msg != NULL )		// Repeat until list is empty ...
	{
		MSG *next = msg->next;		// Cache ref to next MSG in list so that we will have a valid link after this MSG's memory is released.
		free( msg );				// Free memory used by the MSG object.
		msg = next;					// Advance to the next MSG object in linked list, if there is one.
	}

	*chain = NULL;		// Indicate list is now empty.
}

//////////////////////////////////////////////////////////////////////////
// Create MSG objects and chain them together.

MSG *CreateMsgChain( int nobjects, MSGSET *owner )
{
	MSG *chain = NULL;

	for ( ; nobjects > 0; nobjects-- )
	{
		// Create unlinked object. Abort if failed.
		MSG *msg = MsgCreate( owner );
		if ( msg == NULL )
		{
			DestroyMsgChain( &chain );
			break;
		}

		// Add new MSG to chain.
		msg->next	= chain;	// Link the existing list as the list tail.
		chain		= msg;		// Link the specified item as the list head.
	}

	return chain;
}

////////////////////////////////////////////////////////////////////////////
// Open access to a linked list that behaves as either a fifo or a pool.
// High/low watermarks and handler may be installed later if needed.
// MUST BE CALLED BEFORE USING THE FIFO/POOL.
// Imports:
//	m			- pointer to MSGSET object
//	useSem		- set to TRUE if list consumers require blocking signal
//	itemCount	- number of MSG objects to create
//	capacity	- max number of MSG objects expected to belong to fifo/pool
// Returns error code.

// Generic helper.
static int MsgSetOpen( MSGSET *m, BOOL useSem, int itemCount, u32 capacity )
{
	// Create critical section used for atomic access.
	if ( ( m->cs = osdCriticalSectionCreate() ) == NULL )
		return ERR_CRITSECTCREATE;

	// Register type as FIFO or POOL and populate accordingly. Pools are initially populated, while fifos are not.
	if ( itemCount == 0 )
	{
		m->type = MSGSET_TYPE_FIFO;		// It's a fifo, so exit now -- fifos are initialized to empty.
	}
	else
	{
		// It's a pool, so create MSG objects and put them in the pool.
		m->type = MSGSET_TYPE_POOL;
		m->list = CreateMsgChain( itemCount, m );
		if ( m->list == NULL )
			return ERR_MALLOC;
	}
	
	// Create mutex used to signal threads waiting for MSG objects from the fifo/pool.
	if ( useSem )
	{
		if ( ( m->semaphore = osdSemaphoreCreate( itemCount, capacity ) ) == NULL )
			return ERR_CREATEMUTEX;
	}

	return ERR_NONE;
}

//////////////////////////////////////////////////////////////////
// Close access to a fifo or pool.
// MUST BE CALLED BEFORE CLOSING THE API.
// Note: any objects in the fifo/pool are destroyed.

static void MsgSetClose( MSGSET *m )
{
	if ( m != NULL )
	{
		DestroyMsgChain( &m->list );			// Destroy MSG objects in list.
		SemaphoreDestroy( &m->semaphore );		// Destroy consumer's signal mutex.
		CriticalSectionDestroy( &m->cs );		// Destroy critical section used for atomic access control.
	}
}

/////////////////////////////////////////////////////////////////////
// Remove MSG object from a fifo or pool.
// Imports:
//	m			- fifo or pool from which MSG object is to be removed
//	wait		- set to TRUE to block if no object is available
//	terminate	- signal that indicates shutdown termination. Set to NULL if not needed.
// Returns MSG or NULL:
//	NULL if terminate flag signaled, else
//	existing MSG from list if available, else
//  newly created MSG (or NULL if creation failed) if list is a pool and has no watermarks, else
//	NULL if non-blocking call

static MSG *MsgPend( MSGSET *m, BOOL wait, BOOL *terminate )
{
	MSG *msg = NULL;

	if ( m != NULL )
	{
		do		// Wait for signal (indicating list addition) and then loop; exit if semaphore returns unsignaled
		{
			// Abort if terminate flag is specified and asserted.
			if ( terminate != NULL )
				if ( *terminate )
					break;
			
			if ( SemaphorePend( m->semaphore, wait ) )		// Wait for signal (indicating list addition) and then loop; exit if semaphore returns unsignaled
			{
				osdCriticalSectionEnter( m->cs );	// protect ----------

				// Remove object from fifo/pool (linked list) if there is one in the list. Objects are always removed from the list
				// head whether fifo or pool. MSGs' are added to fifo tails and removed from the head, while it doesn't matter with pools.
				msg = MsgRemoveListHead( &m->list );

				// Handle low water level if warranted. If msg was successfully removed from list ...
				if ( msg != NULL )
				{
					// If the water level of this pool/fifo is being monitored ...
					if ( m->watermarkHandler != NULL )
					{
						// Call the notification function if the pool's object count just dropped below the low water mark.
						if ( MsgListLen( m->list ) == m->lowater )
							m->watermarkHandler( m->sess, FALSE );
					}
				}

				osdCriticalSectionLeave( m->cs );	// unprotect ----------

				// Return MSG if we got one from the list.
				if ( msg != NULL )
					break;
			}

			// Create and return new MSG (or NULL if MSG creation failed) if list doesn't use watermarks. It is implied that
			// pools having no watermarks require a new MSG object to be created if one is needed but not available from the
			// pool. Such newly created objects are owned by the associated pool and will be returned to it when released.
			if ( ( m->type == MSGSET_TYPE_POOL ) && ( m->watermarkHandler == NULL ) )
			{
				msg = MsgCreate( m );
				break;
			}
		}
		while ( wait );		// no objects available, so exit if non-blocking call
	}

	return msg;
}

/////////////////////////////////////////////////////////////////////////
// Add MSG object to a fifo or pool.
// In case of fifo, append to tail, but ahead of lower priority MSGs.

static void MsgPost( MSGSET *m, MSG *msg, uint priority )
{
	register MSG *item;

	if ( ( m != NULL ) && ( msg != NULL ) )
	{
		// Assign priority level to the MSG being posted.
		msg->priority = priority;

		osdCriticalSectionEnter( m->cs );	// Protect -------------

		item = m->list;		// Cache pointer to list head.

		// If list is empty, add new MSG at head of list.
		if ( item == NULL )
			m->list = msg;

		// If list is not empty, add MSG to fifo/pool (i.e., append to linked list tail/head respectively).
		else
		{
			if ( m->type == MSGSET_TYPE_FIFO )	// If a fifo ...
			{
				// Append MSG to the tail of the list, but ahead of all lower-priority MSG objects.
				// Find the first lower priority msg or, if there is no lower priority msg, the msg at the end of the list.
				while ( item->next != NULL )
				{
					// If new msg has higher priority than next msg ...
					if ( priority > item->next->priority )
					{
						msg->next = item->next;		// Insert new msg before next msg: chain next msg onto end of new msg.
						break;
					}

					item = item->next;
				}

				item->next = msg;		// Insert new msg into list.
			}
			else	// if MSGSET_TYPE_POOL:
			{
				// Insert MSG at the head of list (disregard priority).
				msg->next	= item->next;	// Link existing list as the tail of new MSG.
				item->next	= msg;			// Assign new MSG as the list head.
			}

			// If the water level of this pool/fifo is being monitored ...
			if ( m->watermarkHandler != NULL )
			{
				// Call the notification function if the pool's object count just rose above the high water mark.
				if ( MsgListLen( m->list ) == m->hiwater )
					m->watermarkHandler( m->sess, TRUE );
			}
		}

		// Signal NotEmpty to unblock waiting thread, if there is one.
		SemaphorePost( m->semaphore );

		osdCriticalSectionLeave( m->cs );	// Unprotect -----------
	}
}

////////////////////////////////////////////////////////////////
// Return MSG to the pool that owns it and NULL its reference.

static void MsgReturnToPool( MSG **pmsg )
{
	if ( pmsg != NULL )
	{
		MSG *msg = *pmsg;
		if ( msg != NULL )
		{
			msg->len		= 0;								// Indicate empty MSG buffer.
			msg->rdIndex	= 0;
			MsgPost( msg->owner, msg, MSG_PRIORITY_NORMAL );	// Return MSG to its pool
			*pmsg = NULL;										// NULL the reference
		}
	}
}

/////////////////////////////////////////////////////////////////////////
// Copy a MSG object and add the copy to a fifo.
// The original object is not modified.
// The copy is allocated from the pool that owns the original object.

static void MsgPostCopy( MSGSET *m, MSG *original, int priority )
{
	if ( m != NULL )
	{
		// Allocate MSG from pool that owns the original. If successful ...
		MSG	*copy = MsgPend( original->owner, FALSE, NULL );
		if ( copy != NULL )
		{
			*copy = *original;				// Duplicate MSG.
			MsgPost( m, copy, priority );	// Send it to target fifo.
		}
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////  ENDIAN ADJUSTMENT  ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
// Detect cpu endianness and, if it's little endian, perform host-network byte reordering.

static const u32 EndianTest = 1;

static u16 hton16( u16 x )
{
	if ( *(u8 *)&EndianTest )	// if little endian cpu
	{
		u8 y[2] = { ((u8 *)&x)[1], ((u8 *)&x)[0] };
        return *(u16 *)&y;
        //return (y[0] + (y[1] << 8));
	}

	return x;
}

static u32 hton32( u32 x )
{
	if ( *(u8 *)&EndianTest )	// if little endian cpu
	{
		u8 y[4] = { ((u8 *)&x)[3], ((u8 *)&x)[2], ((u8 *)&x)[1], ((u8 *)&x)[0] };
//      return (y[0] + (y[1] << 8) + (y[2] << 16) + (y[3] << 24));
        return *(u32 *)&y;
	}

	return x;
}

#define ntoh16(x)		hton16(x)
#define ntoh32(x)		hton32(x)


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  DEBUG LOGGER  ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define DEBUGLOG_INDEX_MASK		( sess->logbufSize - 1 )


// Append bytes to debug ring buffer.
static void DebugLogAppend( SESSION *sess, const char *msg, uint nbytes )
{
	u32 maxA = sess->logbufSize - sess->logIndex;			// Max possible size for a one-block copy.
	u32 sizeA = MIN( nbytes, maxA );						// Size of first (and possibly only) block to copy.
	u32 sizeB = nbytes - sizeA;								// Size of second block, if there is one.

	memcpy( &sess->logbuf[sess->logIndex], msg, sizeA );	// Copy first block.
	memcpy( sess->logbuf, msg + sizeA, sizeB );				// If there's more data, copy second block.

	sess->logIndex = ( sess->logIndex + nbytes ) & DEBUGLOG_INDEX_MASK;	// Bump index, adjust for wraparound.

	sess->logCount += nbytes;								// Bump buffer count,
	if ( sess->logCount > sess->logbufSize )				//   but stop counting when buffer has wrapped around (i.e., full).
		sess->logCount = sess->logbufSize;
}

/////////////////////////////////////////////////////////////////
// API: Copy debug log to application buffer, up to bufsize.
// Returns number of bytes copied.

u32 SessionLogCopy( SESSION *sess, u8 *buf, u32 bufsize )
{
	u32 xfercount = MIN( bufsize, sess->logCount );

	u32 sizeB = MIN( xfercount, sess->logIndex );
	u32 indexB = sess->logIndex - sizeB;

	u32 sizeA = xfercount - sizeB;
	u32 indexA = sess->logbufSize - sizeA;

	memcpy( buf, &sess->logbuf[indexA], sizeA );
	memcpy( buf + sizeA, &sess->logbuf[indexB], sizeB );

	return xfercount;
}

/////////////////////////////////////////////////////////////////
// API: Print most recent debug log data to stdout.
// Imports:
//	maxchar - specifies max number of chars to print.

void SessionLogPrint( SESSION *sess, u32 maxchars )
{
	u32	lastindex = sess->logIndex;
	u32 xfercount = MIN( maxchars, sess->logCount );

	if ( xfercount > 0 )
	{
		u32 index = ( lastindex - xfercount ) & DEBUGLOG_INDEX_MASK;

		char *buf = malloc( sess->logbufSize );

		if ( buf != NULL )
		{
			char *pbuf = buf;

			do
			{
				char c = sess->logbuf[index++];

				*pbuf++ = ( ( c >= 0x20 ) && ( c < 0x7F ) ) ? c : '.';

				index &= DEBUGLOG_INDEX_MASK;
			}
			while ( index != lastindex );

			*pbuf = 0;		// asciiz terminate

			printf( "SessLog: %s\n", buf );

			free( buf );
		}

		else
			printf( "ERROR: CAN'T CREATE PRINT LOG\n" );
	}
}

/////////////////////////////////////////////////////////////////
// API: Enable/disable debug logging.
// This can be called even when session is closed.
// Call to enable logging before opening session if logging is
// needed during the open.
// Returns TRUE if successful.

BOOL SessionLogEnable( SESSION *sess, BOOL enable )
{
	if ( sess->logEnable != enable )
	{
		if ( !enable )
			sess->logCount = 0;					// If disabled, log buffer is empty.
		else if ( sess->logbuf == NULL )
			return FALSE;

		sess->logEnable	= enable;				// Enable/disable logging.
	}

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  SOCKET I/O  /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// Allocate a MSG object from the rx free object pool.
// If the pool drops below the low water mark, this will arrange to send FLOWCTRL_OFF to the server.
// Returns object pointer if successful, or NULL if (a) no objects available or (b) termination flag asserted.

static MSG *RxmsgAlloc( SESSION *sess, MSGTYPE type )
{
	// Extract first MSG object from pool and compute number of objects remaining in the pool.
	MSG	*msg = MsgPend( &sess->RxmsgPool, TRUE, &sess->TelnetTerminateSignal );

	// This should be null only if session is terminating. If not terminating ...
	if ( msg != NULL )
	{
		// Initialize rx MSG object.
		msg->type = type;		// data classification
	}

	return msg;				// Return rx MSG object handle.
}

//////////////////////////////////////////////////////////////////////
// Wait for rx char available or socket error.
// Returns socket wait result code.
// Imports:
//	rxchar - receives rx char, if available.

static SOCKWAIT_RESULT GetRxChar( SESSION *sess, char *rxchar )
{
	SOCKWAIT_RESULT waitResult;
	u32				len;

	do		// Repeat until socket error or in-band char received.
	{
		// Determine if rx data is available. This returns immediately whether or not data is available.
		// Returns: 0 (no data available) | SOCKET_RECV_OOB | SOCKET_RECV_INBAND | SOCKET_RECV_ERROR
		waitResult = ( osdSocketWaitRd( sess->socket, 0 ) );

		// If no rx data is available ...
		if ( ( waitResult != SOCKET_RECV_INBAND ) && ( waitResult != SOCKET_RECV_OOB ) )
		{
			// If any rx stream data has accumulated, flush it out to AppRxThread and start a new accumulation.
			if ( sess->RxmsgCurrent != NULL )		// If stream MSG exists ...
			{
				if ( sess->RxmsgCurrent->len > 0 )		// If MSG contains data ...
				{
					MsgPost( &sess->RxmsgFifo, sess->RxmsgCurrent, MSG_PRIORITY_NORMAL );	// Flush accumulated stream data.
					sess->RxmsgCurrent = RxmsgAlloc( sess, MSGTYPE_STREAM );				// Start new stream accumulation.
				}
			}

			waitResult = osdSocketWaitRd( sess->socket, ~0 );		// Block until rx data is available or socket error.
		}
	}
	while ( waitResult == SOCKET_RECV_OOB );	// 24xx never sends oob, so drop oob chars (this should never happen)

	len = osdSocketRecv( sess->socket, rxchar, 1, FALSE );	// Fetch char from socket.


	if ( len == 0 )		// If no char was received ...
	{
		waitResult = SOCKET_RECV_ERROR;				// connection may have closed, so simulate error
		SessionErrorAssert( sess, ERR_TIMEOUT );	// Select indicated that there was read data, but the read got none. This occurs when the socket has closed.
	}

	return waitResult;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Add received app char to the rxmsg currently being constructed by rx packetizer thread.
// If the rxmsg buffer becomes full, it will be sent and another rxmsg will be allocated to take its place.

static void EnqueueRxchar( SESSION *sess, char c )
{
	MSG *msg = sess->RxmsgCurrent;		// Cache pointer to rxmsg under construction.

	if ( msg != NULL )
	{
		msg->data[msg->len++] = c;				// Append char to rxmsg data buffer.

		if ( msg->len == sizeof( msg->data ) )	// If data buffer is full ...
		{
			MsgPost( &sess->RxmsgFifo, msg, MSG_PRIORITY_NORMAL );		// Send rxmsg to app rxthread.
			sess->RxmsgCurrent = RxmsgAlloc( sess, MSGTYPE_STREAM );	// Start a new rxmsg.
		}
	}
}


////////////////////////////////////////////////////////////////////////////////////////////
// Blocking call: Wait for and then fetch received stream data into buf.
// Buf is filled up to bufsize, or all available chars, whichever is smaller.
// Note: Executes in application's RxThread context.
// Note: Telnet commands previously stripped from stream.
// Note: Drops affected data if RxFlush in progress.
// Imports:
//	wait	- Set to TRUE to block if no data available, or FALSE to return immediately.
// Returns:
//	nbytes in buf[] if successful.
//	-1 if line state changes, in which case line state will be stored in buf[0].
//	0 if no data available, or connection timed out or closed.

#define SESSREAD_LINECHANGE			(-1)

// Helper: Read stream data into buf. Read lock must be acquired before calling this, and released upon exit.
static int SessionStreamReadHelper( SESSION *sess, char *buf, int bufsize, BOOL wait )
{
	int		nbytes		= 0;			// No stream bytes read yet.
	char	*pAppbuf	= buf;			// Appbuf NextWrite pointer.

	while ( TRUE )
	{
		// Get MSG ----------------------------------------------------------

		// If there is no in-process MSG then get the next MSG object ...
		if ( sess->AppRxmsg == NULL )
		{
			// Wait for next MSG to arrive if this is the first pass (nbytes == 0). Otherwise, we
			// previously copied some stream data to appbuf so don't block if no MSG is available.
			sess->AppRxmsg = MsgPend( &sess->RxmsgFifo, wait && ( nbytes == 0 ), &sess->TelnetTerminateSignal );

			// Abort if session is terminating.
			if ( sess->TelnetTerminateSignal )
				return 0;

			if ( sess->AppRxmsg == NULL )
				return nbytes;				// Exit if no MSG is available (previously copied stream data is in buf).

			// If we already copied some stream data (i.e., during previous pass) and this MSG type is
			// not stream data then exit now -- we will process the new MSG next time this function is called.
			if ( ( nbytes > 0 ) && ( sess->AppRxmsg->type != MSGTYPE_STREAM ) )
				return nbytes;
		}
		
		// Process MSG -------------------------------------------------------

		// Decode the MSG type.
		switch ( sess->AppRxmsg->type )
		{
		case MSGTYPE_STREAM:

			// If not comport rx flushing then this is our next in-process MSG, otherwise drop it (i.e., flush it) and loop back for the next one.
			if ( sess->FlushingComportRx == 0 )
			{
				int msglen = sess->AppRxmsg->len - sess->AppRxmsg->rdIndex;		// Compute amount of unconsumed stream data in MSG.

				// If there is unconsumed data in MSG ...
				if ( msglen > 0 )
				{
					// Compute transfer size: smaller of app bufspace or remaining MSG len.
					int xfersize = MIN( msglen, bufsize - nbytes );

					// Consume data from MSG and store it to app buf.
					memcpy( pAppbuf, sess->AppRxmsg->data + sess->AppRxmsg->rdIndex, xfersize );
					sess->AppRxmsg->rdIndex	+= xfersize;
					pAppbuf					+= xfersize;
					nbytes					+= xfersize;

					// Exit without releasing MSG if appbuf is full, because MSG may contain more stream data.
					// Otherwise we will continue and release the MSG because it must have just become depleted.
					if ( bufsize == nbytes )
						return nbytes;
				}
			}

			break;

		case MSGTYPE_TELNET_BRK:

			// Remote comport has just closed, and this is the EndOfComportStream marker. All stream data after this must be
			// coming from the remote shell intepreter. (in fact, a shell prompt should be the next thing to arrive).
			// Switch off rx stream disposal, as we are now interested in the stream data.
			sess->FlushingComportRx = 0;
			break;

		case MSGTYPE_CPC_SUBCOMMAND:

			// Discard MSG if session not attached to comport.
			if ( sess->ComportAttached )
			{
				// Decode and process the cpc command.
				switch ( sess->AppRxmsg->data[0] )
				{
				case CPC_NOTIFY_LINE:	// Linestate change notification from server.

					// If the rx pipeline is currently being flushed then ignore line state changes until EndOfFlush marker is encountered in the stream.
					if ( sess->FlushingComportRx > 0 )		// ignore if rx flushing
						break;

					buf[0] = sess->AppRxmsg->data[1];		// copy linestate to buf[0] so application can access it
					MsgReturnToPool( &sess->AppRxmsg );		// release MSG
					return SESSREAD_LINECHANGE;				// return error code to app to indicate linestate change

				case CPC_REPLY(CPC_PURGE_DATA):		// Acknowledgement of server's tx flush (and therefore our rx flush).

					// It's an rx flush reply (i.e., EndOfFlush marker), so decrement flush count and release the MSG.
					if ( ( sess->FlushingComportRx > 0 ) && ( sess->AppRxmsg->type == CPC_PURGE_DATA ) )
						sess->FlushingComportRx--;					// dec flush count.
					break;
				}
			}

			break;

		default:
			break;
		}

		// Release MSG to its pool and indicate we are not processing a MSG. This will cause us to immediately get the next MSG.
		MsgReturnToPool( &sess->AppRxmsg );
	}
}

// Acquire lock while reading stream data.
int SessionStreamRead( SESSION *sess, S24XXERR *err, char *buf, int bufsize, BOOL wait )
{
	int rtnval = 0;		// in case no data available

	// Acquire ReadAccess lock.
	if ( MutexPend( sess->ReadMutex, wait ) )	// can fail if (1) another thread reading, or (2) session is being terminated by app
	{
		rtnval = SessionStreamReadHelper( sess, buf, bufsize, wait );
		MutexPost( sess->ReadMutex );
	}
	else if ( sess->TelnetTerminateSignal )		// if session is being terminated by the app
		*err = ERR_CONNCLOSED;

	return rtnval;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// API function: fetch remote shell command response (up to '>' prompt) into session object's internal rx buffer.
// Logs internal errors: ERR_TIMEOUT, ERR_BINARYMODE
// Imports:
//	requirePrompt - TRUE to require prompt at end of response. FALSE if any fractional response is sufficient (i.e., Reboot command).
// Returns:
//	success: Pointer to asciiz string.
//	error:   Pointer to empty string.

#define MAX_REBOOT_RESPONSE_TIME	1.0		// Time (in seconds) to wait for reply from Reboot command.

char *SessionReadUntilPrompt( SESSION *sess, S24XXERR *err, BOOL requirePrompt )
{
	u8	*pbuf = sess->appbuf;				// Init buffer pointer.
	int	space = SESSION_BUFSIZE - 1;		// Cache remaining buffer space, allowing for nul at end of max-sized string.

	// If response is required but its content is to be ignored, consume exit with empty response string.
	// This handles the case of the Reboot command, which issues "<CRLF>bye<CRLF>" without a trailing prompt.
	// Wait for any fractional response (via polling), or timeout, whichever occurs first.
	if ( !requirePrompt )
	{
		double tstart = osdCurrentTime();

		do
		{
			// Fetch received stream data, if any, but don't block if data unavailable. Exit loop if any data was
			// received, thus indicating a Reboot command ack from the 24xx.
			if ( SessionStreamRead( sess, err, (char*)pbuf, space, FALSE ) != 0 )
				break;
		}
		while ( osdElapsedTime( tstart ) < MAX_REBOOT_RESPONSE_TIME );
	}

	// If prompt is required at end of command response (i.e., if not a Reboot cmd) ...
	else
	{
		// Repeat until (1) telnet server's prompt is found at end of stream, or (2) response buffer is full, or (3) socket closed ...
		do
		{
			// Fetch received stream data.
			int nrecvd = SessionStreamRead( sess, err, (char*)pbuf, space, TRUE );

			// Done if we timed out waiting for response data.
			if ( nrecvd == 0 )
			{
				SessionErrorAssert( sess, ERR_TIMEOUT );
				*err = ERR_TIMEOUT;
				pbuf = sess->appbuf;
				break;
			}

			// Bump buffer pointer and available buffer space.
			pbuf	+= nrecvd;
			space	-= nrecvd;

			// If telnet server's prompt is found at end of stream ...
			if ( *( pbuf - 1 ) == '>' )
			{
				// Delete prompt in preparation for parsing.
				for ( --pbuf; pbuf > sess->appbuf; pbuf-- )
				{
					char c = *( pbuf - 1 );
					if ( ( c != '\n' ) && ( c != '\r' ) )
						break;
				}

				break;			// Response is now complete.
			}
		}
		while ( space > 0 );
	}

	*pbuf = 0;						// Add a string terminator
	return (char*)sess->appbuf;		// Return string pointer.
}

///////////////////////////////////////////////////////////////////////
// Send stream data to TxSerializerThread for transmission to server.
// Imports:
//	buf		- stream data to be sent.
//	nbytes	- size of stream data.
//	wait	- set to TRUE to block until all data is sent.
// Returns number of bytes sent if successful, or zero upon error (e.g., connection closed).

int SessionStreamWrite( SESSION *sess, S24XXERR *err, const char* buf, int nbytes, BOOL wait )
{
	MSG			*msg;
	char		*dst;
	char		*dstend;
	const char	*src = buf;
	const char	*srcend = buf + nbytes;

	if ( nbytes > 0 )
	{
		// Repeat until all stream data has been sent to TxSerializerThread ...
		do
		{
			// Acquire MSG object from the tx stream pool. The pool only owns one MSG object, so it will be available
			// only if there is no other tx stream MSG already in play. 
			msg = MsgPend( &sess->TxmsgStreamPool, wait, &sess->TelnetTerminateSignal );
			if ( sess->TelnetTerminateSignal )
			{
				SessionErrorAssert( sess, ERR_CONNCLOSED );
				*err = ERR_CONNCLOSED;
				return 0;
			}
			if ( msg == NULL )
				break;			// abort if failed
			
			// Copy a chunk of appdata to MSG, escaping IAC chars as required. Number of bytes copied is the smaller of the remaining unsent data size or
			// MSG capacity. Limit MSG capacity to bufsize-1 to allow for the case of an IAC occuring at the end of the block transfer.
			dst		= (char*)msg->data;
			dstend	= dst + sizeof( msg->data ) - 2;	// limit to bufsize-1
			do
			{
				if ( *src == IAC )	// Get next char. If IAC then append IAC escape to MSG.
					*dst++ = *src;
				
				*dst++ = *src++;	// Append char to MSG.
			}
			while ( ( dst < dstend ) && ( src < srcend ) );

			// Either MSGbuf is full or source data is depleted, so send MSG to TxSerializerThread, which in turn will transmit it via session's socket.
			msg->len  = dst - (char*)msg->data;
			msg->type = MSGTYPE_STREAM;
			MsgPost( &sess->TxmsgFifo, msg, MSG_PRIORITY_NORMAL );
		}
		while ( src < srcend );
	}

	return src - buf;	// return nbytes sent
}

/////////////////////////////////////////////////////////////////////////
// Issue telnet command to server and return its reply in same buffer.
// Note: assumes command and reply have same size.
// Returns TRUE if successful, else FALSE.

BOOL SessionTelnetExec( SESSION *sess, u8* buf, int bufsize )
{
	MSG *msg;
	BOOL rtnval = FALSE;

	// Abort if telnet command won't fit into a MSG payload buffer.
	if ( bufsize <= sizeof( msg->data ) )
	{
		// Acquire MSG object from the ctrl msg pool. Abort if failed.
		if ( ( msg = MsgPend( &sess->CtrlMsgPool, TRUE, &sess->TelnetTerminateSignal ) ) != NULL )
		{
			// Copy telnet command to MSG.
			memcpy( msg->data, buf, bufsize );
			msg->len  = bufsize;
			msg->type = MSGTYPE_TELNET_COMMAND;

			osdCriticalSectionEnter( sess->critsectTelnet );	// Only one telnet command in play at a time --------------------------------

			// Send MSG to TxSerializerThread, which in turn will transmit it via session's socket.
			MsgPost( &sess->TxmsgFifo, msg, MSG_PRIORITY_NORMAL );

			// Wait for telnet reply from server. Discard telnet replies until we receive the expected one or error.
			while ( ( msg = MsgPend( &sess->RxCpcReplyFifo, TRUE, &sess->TelnetTerminateSignal ) ) != NULL )
			{
				// If cpc reply code corresponds to the one sent in the telnet command ...
				if ( msg->data[0] == CPC_REPLY(buf[3]) )
				{
					memcpy( buf, msg->data, bufsize );		// Copy reply to caller's buffer.
					rtnval = TRUE;
					break;
				}
			}

			osdCriticalSectionLeave( sess->critsectTelnet );	// --------------------------------
		}
	}

	return rtnval;		// return TRUE if successful
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////  TELNET COMMAND PARSER  ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
// Map cpc option code into value size.
// Returns TRUE if valid option code, else FALSE.

static BOOL GetCpcValueSize( u8 option, int *valsize )
{
	// If it's a cpc option reply, convert to associated command code.
	if ( option >= CPC_REPLY(0) )
		option -= CPC_REPLY(0);

	// Map command code to value size.
	switch ( option )
	{
	case CPC_BAUDRATE:
		*valsize = 4;
		break;

	case CPC_DATABITS:
	case CPC_PARITY:
	case CPC_STOPBITS:
	case CPC_CONTROL:
	case CPC_MASK_LINE:
	case CPC_MASK_MODEM:
	case CPC_PURGE_DATA:
		*valsize = 1;
		break;

	case CPC_FLOW_SUSPEND:
	case CPC_FLOW_RESUME:
		*valsize = 0;
		break;

	default:
		return FALSE;	// illegal or unsupported option
	}

	return TRUE;	// valid option code
}

//////////////////////////////////////////////////////
// Fetch next received telnet char from stream.

static char GetTelnetChar( SESSION *sess )
{
	char c;

	// Abort if error previously logged.
	if ( sess->LastError == ERR_NONE )
	{
		switch ( GetRxChar( sess, &c ) )
		{
		case SOCKET_RECV_INBAND:
			return c;

		case SOCKET_RECV_ERROR:
			SessionErrorAssert( sess, ERR_SOCKET );
			break;

		case SOCKET_RECV_OOB:
		case SOCKET_RECV_TIMEOUT:
		default:
			break;
		}
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////
// Fetch specified number of telnet command chars into buf.
// Imports:
//	nchars - number of telnet chars following IAC SB CPC, not including IAC SE at end of command.
// Returns TRUE if successful and IAC SE present at end of buf.

static BOOL GetCpcRemainder( SESSION *sess, char *buf, int nchars )
{
	char *pbuf = buf;

	nchars += 2;		// Be sure to read IAC SE chars at end of telnet command.

	// Fetch chars into buf.
	for ( ; nchars > 0; nchars-- )
		*pbuf++ = GetTelnetChar( sess );

	// Return TRUE if IAC SE present at end of command.
	return ( ( *(pbuf-2) == IAC ) && ( *(pbuf-1) == SE ) );
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Fetch remainder of telnet cpc option, allocate MSG and populate it with cpc subcmd & value[].
// Returns resulting MSG, or NULL if error.

static MSG *ConstructForwardCpcMsg( SESSION *sess, char subcmd, MSGTYPE type )
{
	u8	buf[50];		// Telnet command buffer.
	int	valsize;
	MSG	*msg = NULL;

	buf[0] = subcmd;		// prime buf with telnet subcmd char

	// Determine cpc option's value size. Done if invalid subcommand.
	if ( GetCpcValueSize( subcmd, &valsize ) )
	{
		if ( GetCpcRemainder( sess, (char*)buf + 1, valsize ) )	// Fetch value[] from telnet cmd into buf.
		{
			msg = MsgPend( &sess->CtrlMsgPool, FALSE, NULL );	// alloc msg
			msg->type = type;									// classify msg
			msg->len  = valsize + 1;							// specify msg size in bytes
			memcpy( msg->data, buf, valsize + 1 );				// populate msg buf: subcmd, value[]
		}
	}

	return msg;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Fetch and execute a telnet command. This is called when an IAC char, which may
// signal the beginning of a telnet command, is encountered in the rx stream.
// It's possible, though, that the char is an escaped IAC in the stream.
// Appends char to current telnet command and, if command is complete, execute it.

static void ParseTelnetCommand( SESSION *sess )
{
	u8		buf[50];				// Telnet command buffer.
	char	subcmd;
	char	*pbuf = (char*)buf;
	MSG		*msg;

	// Fetch and decode the telnet command code that follows the initial IAC.
	switch ( GetTelnetChar( sess ) )
	{
	case IAC:		// Escaped stream char ---------------------------------

		EnqueueRxchar( sess, (char)IAC );		// Send stream char to AppRxThread.
		return;									// False alarm: we are not processing a telnet command.
		
	case DO:		// Option negotiation ----------------------------------

		switch ( GetTelnetChar( sess ) )		// Fetch and decode the option type code.
		{
		case TELOPT_BINARY:	sess->TxBinaryMode = TRUE;	return;		// Server says we can send binary to it (response to our WILL).
		case TELOPT_ECHO:
		case TELOPT_CPC:
		default:										return;
		}

	case DONT:		// Option negotiation ----------------------------------

		switch ( GetTelnetChar( sess ) )		// Fetch and decode the option type code.
		{
		case TELOPT_BINARY:	sess->TxBinaryMode = FALSE;	return;		// Server says we can send ascii to it (response to our WONT).
		case TELOPT_ECHO:
		case TELOPT_CPC:
		default:										return;
		}

	case WILL:		// Option negotiation ----------------------------------

		switch ( GetTelnetChar( sess ) )		// Fetch and decode the option type code.
		{
		case TELOPT_BINARY:	sess->RxBinaryMode = TRUE;	return;		// Server says it is sending us binary (response to our DO).
		case TELOPT_ECHO:	sess->EchoEnable   = TRUE;	return;
		case TELOPT_CPC:	sess->CpcEnable    = TRUE;	return;
		default:										return;
		}

	case WONT:		// Option negotiation ----------------------------------

		switch ( GetTelnetChar( sess ) )		// Fetch and decode the option type code.
		{
		case TELOPT_BINARY:	sess->RxBinaryMode = FALSE;	return;		// Server says it is sending us ascii (response to our DONT).
		case TELOPT_ECHO:	sess->EchoEnable   = FALSE;	return;
		case TELOPT_CPC:	sess->CpcEnable    = FALSE;	return;
		default:										return;
		}

	case SB:		// Subnegotiation --------------------------------------

		if ( GetTelnetChar( sess ) != TELOPT_CPC )		// The only subnegotiation type we support is Telnet Com Port Control. If it's something else,
			return;										//   we never agreed to accept it so just drop the telnet command and return to normal stream mode.

		// Fetch and decode option subcommand.
		*pbuf++ = subcmd = GetTelnetChar( sess );
		switch ( subcmd )
		{
		case CPC_NOTIFY_LINE:
		case CPC_NOTIFY_MODEM:
			// Forward line/modem events to RxThread.
			MsgPost( &sess->RxmsgFifo, ConstructForwardCpcMsg( sess, subcmd, MSGTYPE_CPC_SUBCOMMAND ), MSG_PRIORITY_NORMAL );
			return;

		case CPC_REPLY(CPC_PURGE_DATA):
			// Forward purge reply to both RxThread and TxThread.
			msg = ConstructForwardCpcMsg( sess, subcmd, MSGTYPE_CPC_SUBCOMMAND );	// create msg
			MsgPostCopy( &sess->RxCpcReplyFifo, msg, MSG_PRIORITY_NORMAL );			// send copy of msg to TxThread
			MsgPost( &sess->RxmsgFifo, msg, MSG_PRIORITY_NORMAL );					// forward msg to RxThread
			return;

		case CPC_FLOW_SUSPEND:
		case CPC_FLOW_RESUME:
			// Forward FlowControl commands to TxSerializerThread.
			MsgPost( &sess->TxmsgFifo, ConstructForwardCpcMsg( sess, subcmd, MSGTYPE_CPC_SUBCOMMAND ), MSG_PRIORITY_HIGH );
			return;

		case CPC_REPLY(CPC_FLOW_SUSPEND):
		case CPC_REPLY(CPC_FLOW_RESUME):
			// Drop FlowControl replies.
			GetCpcRemainder( sess, pbuf, 0 );
			return;

		case CPC_REPLY(CPC_SIGNATURE):
		case CPC_REPLY(CPC_BAUDRATE):
		case CPC_REPLY(CPC_DATABITS):
		case CPC_REPLY(CPC_PARITY):
		case CPC_REPLY(CPC_STOPBITS):
		case CPC_REPLY(CPC_CONTROL):
		case CPC_REPLY(CPC_NOTIFY_LINE):
		case CPC_REPLY(CPC_NOTIFY_MODEM):
		case CPC_REPLY(CPC_MASK_LINE):
		case CPC_REPLY(CPC_MASK_MODEM):
			// Forward all other CPC replies to TxThread.
			MsgPost( &sess->RxCpcReplyFifo, ConstructForwardCpcMsg( sess, subcmd, MSGTYPE_CPC_SUBCOMMAND ), MSG_PRIORITY_NORMAL );
			return;

		default:
			return;		// Unsupported suboption.
		}

	case BRK:		// Break ----------------------------------------------

		// If session is attached to remote comport, this demarks the end of comport stream data. Otherwise ignore it.
		if ( sess->ComportAttached )
		{
			// Forward BRK message to app's TxThread via RxCpcReplyFifo, which will mark the comport disconnected when it receives the BRK.
			// The TxThread should currently be blocked in ComportClose(), waiting for the BRK to arrive. We also send a copy to RxThread
			// as an EndOfComportStream marker. Upon receipt, RxThread should zero FlushingComportRx, which should have been asserted by ComportClose().

			// Construct a notification message that indicates a telnet BRK message has been received.
			msg = MsgPend( &sess->CtrlMsgPool, FALSE, NULL );	// alloc MSG object
			msg->type = MSGTYPE_TELNET_BRK;						// classify MSG -- no size or data need be provided for this MSGTYPE

			MsgPostCopy( &sess->RxCpcReplyFifo, msg, MSG_PRIORITY_NORMAL );			// Send copy of msg to TxThread, which will negate ComportAttached.
			MsgPost( &sess->RxmsgFifo, msg, MSG_PRIORITY_NORMAL );					// Forward msg to RxThread, which will cancel discarding of incoming stream data.
		}
		return;

	case IP:
	case AO:		// Commands that should never be sent by 2426 ----------
	case AYT:
	case EC:
	case EL:
	case GA:
	case NOP:
	case SE:
	case DM:
	default:
		return;		// Finished telnet command.
	}
}

///////////////////////////////////////////////////////
// Execute shell command on server and return reply.
// Imports:
//	cmd				- asciiz shell command string, with CRLF terminator.
//	requirePrompt	- require prompt at end of response if TRUE, else exit upon any partial response and discard the response (e.g., Reboot cmd).
// Exports:
//	rsp				- asciiz shell response string (unmodified) with shell prompt and CRLF, or empty string upon error.
// Returns pointer to response string.

char *ShellCommandExec( SESSION *sess, S24XXERR *err, const char* cmd, BOOL requirePrompt )
{
	if ( !sess->ComportAttached )	// Legal only if comport is not attached to session.
	{
		int len = strlen( cmd );

		// Send cmd. If successful, fetch and return response.
		if ( SessionStreamWrite( sess, err, cmd, len, TRUE ) == len )
			return SessionReadUntilPrompt( sess, err, requirePrompt );
	}

	// Return empty string.
	sess->appbuf[0] = 0;
	return (char*)sess->appbuf;
}
 
/////////////////////////////////////////////////////////////////////////
// API: Execute shell command and copy response to application buffer.
// Imports:
//	err				- pointer to calling thread's private error code storage.
//	model			- I/O server model number. Set to zero if command is common to all module types.
//	cmd				- shell command.
//	rspbuf			- buffer that receives shell response. Set to NULL if response is not needed by caller.
//	expectedRspSize	- ~0 -- ignore response size and drop response.
//					  <0 -- ignore response size, optionally return response in rspbuf[]. Size of rspbuf is absolute value of expectedRspSize.
//					   0 -- response size must be zero.
//					  >0 -- response size must be specified size, optionally return response in rspbuf[].
// Notes:
//  Session's critical section should be acquired before calling this.
// Returns TRUE if successful.

BOOL SessionExecCmd( HSESSION sess, S24XXERR *err, u16 model, const char *cmd, int expectedRspSize, char *rspbuf )
{
	BOOL rtnval = FALSE;
	char *rspstr;

	// Don't modify TLS error code if a previous error is pending. If no error is pending ...
	if ( *err == ERR_NONE )
	{
		// Return error if session was never successfully opened or handle was valid at one time, but no more.
		if ( !isValidSession( sess ) )
			*err = ERR_INVALIDSESSION;

		else
		{
			// Enter session's critical section.
			osdCriticalSectionEnter( sess->critsectShell );

			// Verify specified model number is the one registered to the session.
			if ( ( model != 0 ) && ( model != sess->svrModel ) )
				*err = ERR_SHELLCOMMAND;

			// Abort if session is attached to a remote comport on the server -- can't execute shell commands while redirected to comport.
			else if ( sess->ComportAttached )
				*err = ERR_COMPORTWASATTACHED;

			else
			{
				// Execute command and fetch cleartext response from the I/O server.
				// Note: newline and prompt, if present, are stripped from end of string.
				rspstr = ShellCommandExec( sess, err, cmd, expectedRspSize != IGNORE_EXPECTEDRSPSIZE );

				// If no command execution errors ...
				if ( *err == ERR_NONE )
				{
					if ( expectedRspSize != IGNORE_EXPECTEDRSPSIZE )	// If response is of interest ...
					{
						// If we are to ignore response size and optionally return response in rspbuf[] ...
						if ( expectedRspSize < 0 )
						{
							if ( rspbuf != NULL )
							{
								if ( strlen(rspstr) >= (uint)(-expectedRspSize) )	// Size of rspbuf is absolute value of expectedRspSize.
									*err = ERR_BUFWOULDOVERFLOW;			// if response too large for buffer
								else
									strcpy( rspbuf, rspstr );
							}
						}

						// If response is required to have specified size, and optionally return response in rspbuf[] ...
						else if ( strlen(rspstr) != (uint)expectedRspSize )
							*err = ERR_RSPSIZE;					// Error -- incorrect size.

						else if ( rspbuf != NULL )
							strcpy( rspbuf, rspstr );			// No error: Fetch command response into thread local storage.
					}

					// Indicate success if no errors detected.
					if ( *err == ERR_NONE )
						rtnval = TRUE;
				}
			}

			// Exit session's critical section.
			osdCriticalSectionLeave( sess->critsectShell );
		}
	}

	return rtnval;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  COMPORT FUNCTIONS  /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define COMBUFSIZE	2048		// 2K com port buffer.


//////////////////////////////////////////////////////////////////////////////
// Verify session handle is valid and model 2426 is registered to session.
// Imports:
//	err			- Pointer to TLS error code.
// Returns TRUE if no errors.

static BOOL SessionValidate2426( SESSION *sess, S24XXERR *err )
{
	// Don't modify TLS error code if a previous error is still pending.
	if ( *err != ERR_NONE )
		return FALSE;

	// Return error if session was never successfully opened or handle was valid at one time, but no more.
	if ( !isValidSession( sess ) )
	{
		*err = ERR_INVALIDSESSION;
		return FALSE;
	}

	// Verify specified model number is the one registered to the session.
	if ( sess->svrModel != 2426 )
	{
		*err = ERR_SHELLCOMMAND;
		return FALSE;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// Return false and assert error if comport is not attached to the session.

static BOOL SessionValidateAttached( SESSION *sess, S24XXERR *err )
{
	if ( SessionValidate2426( sess, err ) )
	{
		if ( sess->ComportAttached )
			return TRUE;

		*err = ERR_COMPORTUNATTACHED;
	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////////
// Connect telnet session to remote comport through remote shell command.
// Imports:
//  baud		 - data rate in bits/second (e.g. 9600)
//  parity		 - 'e','o','n','m','s'
//  data		 - data bits 5,6,7,8,9
//  stop		 - stop bits, 0 (means 1.5), 1, 2
//  rxHandler	 - callback when comport data is received. Set to NULL if callback not used.
//  eventHandler - callback when comport event (e.g., rx break) detected. Set to NULL if not used.

BOOL SessionComportOpen( SESSION *sess, S24XXERR *err, u32 baud, char parity, u8 data, u8 stop )
{
	char cmd[80];

	// Abort if registered server type is incorrect.
	if ( SessionValidate2426( sess, err ) )
	{
		// Abort if comport is already attached to this session.
		if ( sess->ComportAttached )
			*err = ERR_COMPORTWASATTACHED;

		else
		{
			// Direct the server to attach its comport to this telnet session. The only thing we expect back is
			// a telnet prompt, which is consumed by ShellCommandExec(); anything more indicates an error.
			sprintf( cmd, "com %d %c %d %d\r\n", (int) baud, parity, data, stop );

			// Only one shell command in play at a time --------------------------------
			osdCriticalSectionEnter( sess->critsectShell );

			if ( *ShellCommandExec( sess, err, cmd, TRUE ) == 0 )	// If server didn't reject the attach request ...
			{
				if ( *err == ERR_NONE )								// If no session errors detected ...
					sess->ComportAttached = TRUE;					//   Indicate successfully attached.
			}

			osdCriticalSectionLeave( sess->critsectShell );		// Close the CS -------------------------------
		}
	}

	return ( *err == ERR_NONE );
}

//////////////////////////////////////////////////
// Terminate remote comport shell command.
// Returns true if successful.

BOOL SessionComportClose( SESSION *sess, S24XXERR *err )
{
	MSG		*msg;
	MSGTYPE	msgtype;
	BOOL	rtnval = FALSE;	// in case it fails

	// Abort if registered server type is incorrect.
	if ( SessionValidateAttached( sess, err ) )
	{
		osdCriticalSectionEnter( sess->critsectShell );
		
		// From this point on, force RxThread to discard any comport rx stream data in the rx pipeline. RxThread will
		// continue to discard incoming stream data until a telnet BRK is received, indicating end of comport stream.
		sess->FlushingComportRx++;

		// Send IAC IP to invoke ComportClose on the server; don't wait for reply. This will cause the server to close
		// its comport and exit to its shell intepreter. Acquire MSG object from the ctrl msg pool; abort if failed.
		msg = MsgPend( &sess->CtrlMsgPool, TRUE, &sess->TelnetTerminateSignal );
		if ( msg != NULL )	// If MSG successfully allocated ...
		{
			// Copy telnet IP command to MSG and send it to TxSerializerThread, which in turn will transmit it via session's socket.
			msg->data[0]	= IAC;
			msg->data[1]	= IP;
			msg->len		= 2;
			msg->type		= MSGTYPE_TELNET_COMMAND;
			MsgPost( &sess->TxmsgFifo, msg, MSG_PRIORITY_NORMAL );

			// Block until we receive telnet BRK from server, which indicates the end of comport rx data.
			// Discard incoming MSG's until we receive the expected BRK or error.
			do
			{
				msg = MsgPend( &sess->RxCpcReplyFifo, TRUE, &sess->TelnetTerminateSignal );
				if ( msg == NULL )
					break;

				msgtype = msg->type;		// cache MSG type
				MsgReturnToPool( &msg );	// return MSG to its pool

				// If it's a telnet BRK command
				if ( msgtype == MSGTYPE_TELNET_BRK )
				{
					SessionReadUntilPrompt( sess, err, TRUE );	// Wait for prompt that indicates termination of remote comport connection. Ignore errors since we're done.
					sess->ComportAttached = FALSE;				// Mark comport closed.
					rtnval = TRUE;								// success
					break;
				}
			}
			while ( TRUE );
		}

		osdCriticalSectionLeave( sess->critsectShell );
	}
	
	return rtnval;
}

///////////////////////////////////////////////////////////////
// Read binary/ascii data from the comport.
// Imports:
//	buf		- Buffer that will receive rx data.
//	len		- Maximum bytes to receive into buf.
//	wait	- Set to TRUE to wait for data, FALSE to return immediately if no data available.
// Returns:
//	>=0 : number of bytes received in buf.
//	-1  : linestate change notification, with result stored in buf[0].
//	-2  : connection closed.

int SessionComportRead( SESSION *sess, S24XXERR *err, u8 *buf, int len, BOOL wait )
{
	// Read all available rx data from comport, up to len bytes and return byte count.
	if ( SessionValidateAttached( sess, err ) )								// if session valid
		return SessionStreamRead( sess, err, (char*) buf, len, wait );
	else
		return 0;
}

///////////////////////////////////////////////////////////////
// Write binary/ascii data to the comport.
//	buf		- Data to be sent.
//	len		- Number of bytes to send.
//	wait	- Set to TRUE to wait for data, FALSE to return immediately if no data available.
// Returns number of bytes sent, which may be less than len.

int SessionComportWrite( SESSION *sess, S24XXERR *err, u8 *data, int len, BOOL wait )
{
	// Send data to server, return nbytes sent. Abort if comport is closed.	
	if ( SessionValidateAttached( sess, err ) )
		return SessionStreamWrite( sess, err, (char*)data, len, wait );
	else
		return 0;
}

///////////////////////////////////////////////////////////////
// Issue a CPC command to the server and get the reply.
// Returns TRUE if successful.

// Helper.
static BOOL ComportCmdExec( SESSION *sess, u8 command, void *data )
{
	u8		buf[20];
	int		i;
	int		valsize;
	u8		*pbuf = buf;
	void	*pval = &buf[4];
	u8		*pdata = (u8*)data;
	
	// Determine size of cpc value. Abort if unsupported option.
	if ( GetCpcValueSize( command, &valsize ) )
	{
		// Convert data to network standard byte order if necessary.
		switch ( valsize )
		{
		case 2:	*(u16*)data = hton16( *(u16*)data );	break;
		case 4: *(u32*)data = hton32( *(u32*)data );	break;
		}

		// Build the command: { IAC, SB, TELOPT_CPC, command, value[], IAC, SE };
		*pbuf++ = IAC;
		*pbuf++ = SB;
		*pbuf++ = TELOPT_CPC;
		*pbuf++ = command;
		for ( i = 0; i < valsize; i++ )
			*pbuf++ = *pdata++;
		*pbuf++ = IAC;
		*pbuf++ = SE;

		// Send cpc command to 2426 and fetch reply into same cmd buffer.
		// Reply arrives in network byte order, so convert to host order.
		if ( SessionTelnetExec( sess, buf, pbuf - buf ) != FALSE )
		{
			switch ( valsize )
			{
			case 1:	*(u8*)data  = *(u8*)pval;				return TRUE;
			case 2:	*(u16*)data = ntoh16( *(u16*)pval );	return TRUE;
			case 4:	*(u32*)data = ntoh32( *(u32*)pval );	return TRUE;
			}
		}
	}

	return FALSE;
}

// Execute comport command and get reply.
BOOL SessionComportIoctl( SESSION *sess, S24XXERR *err, COMPORT_IOCTL ioctl, void *val )
{
	u8 cmd;

	// Abort if registered server type is incorrect.
	if ( !SessionValidateAttached( sess, err ) )
		return FALSE;
	
	switch ( ioctl )
	{
		// Set comport configuration. Specify 0 to return current value without changing it.
		// Returns actual configuration value, which may differ from specified value if unsupported
		// (e.g., 9625 baud --> 9600 baud)
	case BAUDRATE:	return ComportCmdExec( sess, CPC_BAUDRATE, val );
	case PARITY:	return ComportCmdExec( sess, CPC_PARITY,   val );
	case DATABITS:	return ComportCmdExec( sess, CPC_DATABITS, val );
	case STOPBITS:	return ComportCmdExec( sess, CPC_STOPBITS, val );

	case TXBREAKON:
		cmd = CPC_BREAK_SET_ON;
		return ComportCmdExec( sess, CPC_CONTROL, &cmd );
	case TXBREAKOFF:
		cmd = CPC_BREAK_SET_OFF;
		return ComportCmdExec( sess, CPC_CONTROL, &cmd );
	case RXFLUSH:
		sess->FlushingComportRx++;
		cmd = 2;		// purge accesss server transmit buffer (i.e., client's receive pipeline)
		return ComportCmdExec( sess, CPC_PURGE_DATA, &cmd );
	default:
		return FALSE;	// unsupported ioctl
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////  RX PACKETIZER THREAD  ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////
// Notify TxSerializerThread that high/low water mark has been reached on the RxMsgPool.

static void RxpoolWatermarkHandler( SESSION *sess, BOOL highwater )
{
	// Allocate a MSG object. This is guaranteed to succeed unless we are terminating.
	MSG *msg = MsgPend( &sess->CtrlMsgPool, FALSE, NULL );
	if ( msg != NULL )
	{
		// Populate the MSG with the high/low indication and send it to TxSerializer.
		msg->type = ( highwater ? MSGTYPE_RXPOOL_HIWATER : MSGTYPE_RXPOOL_LOWATER );
		MsgPost( &sess->TxmsgFifo, msg, MSG_PRIORITY_HIGH );
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Rx Packetizer Thread. Blocks on and receives all data from the session's socket.
// Parses incoming telnet commands/replies. Forwards stream data, cpc commands (except
// flowctrl cmds), and TxFlush replies (duplicated) to AppRxThread. Forwards flow commands
// and cpc replies to AppTxThread. Forwards flowctrl replies, bin/cpc negotiations, and
// RxMsgPool low water signals to TxSerializerThread.

static THREAD RxPacketizerThread( SESSION *sess )
{
	char	rxchar;

	do		// Repeat until shutdown signal ...
	{
		// Fetch and decode one rx char.
		switch ( GetRxChar( sess, &rxchar ) )
		{
		case SOCKET_RECV_INBAND:
			if ( rxchar == IAC )					// If processing a telnet command,
				ParseTelnetCommand( sess );			//   pass control to the command interpreter.
			else									// Else
				EnqueueRxchar( sess, rxchar );		//   copy char to app buffer.
			break;

		case SOCKET_RECV_ERROR:
			SessionErrorAssert( sess, ERR_SOCKET );
			break;

		case SOCKET_RECV_OOB:
		case SOCKET_RECV_TIMEOUT:
		default:
			break;
		}
	}
	while ( !sess->TelnetTerminateSignal );

	return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////  TX SERIALIZER THREAD  ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// Send data to session's socket for immediate transmission to server.

BOOL SessionRawWrite( SESSION *sess, const char* buf, int len )
{
	BOOL success;

	// Send data to socket, set rtnval TRUE if successful.
	int wrlen = osdSocketWrite( sess->socket, buf, len );
	success = ( wrlen == len );

	if ( sess->logEnable )	// If debug logging is enabled ...
	{
		DebugLogAppend( sess, "#TX#", 4 );
		if ( success )
			DebugLogAppend( sess, buf, len );
		else
			DebugLogAppend( sess, "ERR_NETWORKWRITE", 16 );
	}

	// Record write error if detected.
	if ( !success )
		SessionErrorAssert( sess, ERR_NETWORKWRITE );

	return success;	// Return TRUE if successful.
}

/////////////////////////////////////////////////////////////////////////////////////////
// TxSerializerThread fetches and processes MSG objects from the session's TxmsgFifo.
// It serializes outgoing data (to server) to ensure that telnet messages are sent out
// as contiguous chunks, thus preventing stream data from corrupting telent commands.

static THREAD TxSerializerThread( SESSION *sess )
{
	MSG		*msg;
	uint	TxFlowDisableLevel	= 0;		// Tx streaming enabled when zero (i.e., /TxFlowEnabled).
	MSG		*TxStreamMsg		= NULL;		// MSG temporarily held over while tx streaming disabled.
	BOOL	CrossedLowWater		= FALSE;	// Low/high water hysteresis memory.
	BOOL	CrossedHighWater	= FALSE;

	// Telnet CPC flow control commands.
	const char resumeMsg[]  = { IAC, SB, TELOPT_CPC, CPC_FLOW_RESUME,  IAC, SE };
	const char suspendMsg[] = { IAC, SB, TELOPT_CPC, CPC_FLOW_SUSPEND, IAC, SE };

	// The middleware always operates in binary mode and uses cpc, so we begin by initiating
	// negotiations with the 2426 to put these in effect. When received, the telnet replies
	// will be intercepted and processed by RxSerializerThread.
	const char TelnetInitMsg[] = {
		IAC, DO,   TELOPT_SGA,			// Tell server not to send us GA (i.e., do suppress go aheads).
		IAC, WILL, TELOPT_SGA,			// Tell server we won't send GA (i.e., will suppress go aheads).
		IAC, DONT, TELOPT_ECHO,			// Tell server not to echo to this automated client.
		IAC, WILL, TELOPT_BINARY,		// Tell server we will send binary.
		IAC, WILL, TELOPT_CPC,			// Tell server we will negotiate Com Port Control options.
		IAC, DO,   TELOPT_BINARY,		// Tell server to send binary.
		IAC, DO,   TELOPT_CPC			// Tell server to negotiate CPC options.
	};

	// Send CPC/BinaryMode initialization commands to 2426.
	SessionRawWrite( sess, TelnetInitMsg, sizeof(TelnetInitMsg) );

	do		// Repeat until thread termination signal ...
	{
		// Wait for available tx MSG or thread termination signal, whichever comes first.
		msg = MsgPend( &sess->TxmsgFifo, TRUE, &sess->TelnetTerminateSignal );

		// Exit thread if session is terminating.
		if ( sess->TelnetTerminateSignal )
			break;

		// Decode and process the message.
		switch ( msg->type )
		{
		case MSGTYPE_RXPOOL_LOWATER:
			// If the level of RxmsgPool just traversed the hysteresis band and fell to the low water mark, tell server to stop sending.
			if ( !CrossedLowWater ) {
				SessionRawWrite( sess, suspendMsg, sizeof(suspendMsg) );
				CrossedLowWater  = TRUE;
				CrossedHighWater = FALSE;
			}
			break;

		case MSGTYPE_RXPOOL_HIWATER:
			// If the level of RxmsgPool just traversed the hysteresis band and rose to the high water mark, tell 2426 to start sending.
			if ( !CrossedHighWater ) {
				SessionRawWrite( sess, resumeMsg, sizeof(resumeMsg) );
				CrossedHighWater = TRUE;
				CrossedLowWater  = FALSE;
			}
			break;

		case MSGTYPE_STREAM:
			// If tx streaming is enabled ...
			if ( TxFlowDisableLevel == 0 )
				SessionRawWrite( sess, (char*)msg->data, msg->len );	// Transmit stream data. Use raw write, because any IAC escapes were previously inserted into stream.
			else
			{
				TxStreamMsg = msg;		// Hold the stream MSG until tx streaming is enabled.
				continue;				// Loop, but don't release the MSG to its pool.
			}
			break;

		case MSGTYPE_CPC_SUBCOMMAND:	// Must be incoming cpc command.
			// Decode and process received cpc command that has been forwarded to us by RxPacketizerThread.
			switch ( msg->data[0] )
			{
			case CPC_FLOW_SUSPEND:
				TxFlowDisableLevel++;
				break;

			case CPC_FLOW_RESUME:
				if ( TxFlowDisableLevel > 0 )		// If streaming is disabled ...
				{
					if ( --TxFlowDisableLevel == 0 )	// Decrease disable count and, if streaming is now enabled ...
					{
						if ( TxStreamMsg != NULL )			// If a stream MSG is being held ...
						{
							SessionRawWrite( sess, (char*)TxStreamMsg->data, TxStreamMsg->len );	// Transmit stream data. Use raw write, because any IAC escapes were previously inserted into stream.
							MsgReturnToPool( &TxStreamMsg );										// Done with the held stream MSG object, so release it to its owner pool and NULL its reference.
						}
					}
				}
				break;
			}
			break;

		case MSGTYPE_TELNET_COMMAND:	// Must be complete, outgoing telnet command ...
			SessionRawWrite( sess, (char*)msg->data, msg->len );		// Transmit telnet command.
			break;

		case MSGTYPE_TELNET_BRK:
		default:
			break;
		}

		// Done with tx MSG object, so release it to its owner pool.
		MsgReturnToPool( &msg );
	}
	while ( !sess->TelnetTerminateSignal );

	// Return any loose MSG objects to their owner pools.
	MsgReturnToPool( &msg );
	MsgReturnToPool( &TxStreamMsg );

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////  SESSION MANAGEMENT  /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define APPBUF_MINSIZE		100			// Minimum allowed size for application receive buffer.

/////////////////////////////
// Open/close the API.

// Returns TRUE if successful, else FALSE.
BOOL SessionApiOpen( void )
{
	return osdSocketIfOpen();
}

void SessionApiClose( void )
{
	osdSocketIfClose();
}

//////////////////////////////////////////////////////////////////////
// API: Close a session and free its resources.
// Session handle is invalid after this function executes.

void SessionClose( SESSION *sess )
{
	if ( !isValidSession( sess ) )
		return;

	// Signal session threads to shutdown.
	sess->TelnetTerminateSignal = TRUE;

	// Close the network connection. This will unblock any threads waiting on the socket.
	SocketDisconnect( &sess->socket );

	// Signal all fifos and pools to unblock any threads that may be waiting on them.
	SemaphorePost( sess->TxmsgFifo.semaphore );
	SemaphorePost( sess->RxmsgFifo.semaphore );
	SemaphorePost( sess->TxmsgStreamPool.semaphore );
	SemaphorePost( sess->RxCpcReplyFifo.semaphore );

	// Wait for session threads to terminate.
	ThreadWaitTerminate( &sess->RxPacketizerThread );
	ThreadWaitTerminate( &sess->TxSerializerThread );

	// Destroy session-level thread synchronization objects.
	MutexDestroy( &sess->ReadMutex );
	CriticalSectionDestroy( &sess->critsectTelnet );
	CriticalSectionDestroy( &sess->critsectShell );

	// Return any loose MSG objects to their pools to ensure they will be freed when pools are destroyed.
	MsgReturnToPool( &sess->AppRxmsg );
	MsgReturnToPool( &sess->RxmsgCurrent );

	// Destroy all fifos/pools and free all objects that are in them. This also destroys all
	// synchronization objects belonging to each fifo/pool.
	MsgSetClose( &sess->RxmsgFifo );
	MsgSetClose( &sess->TxmsgFifo );
	MsgSetClose( &sess->RxCpcReplyFifo );
	MsgSetClose( &sess->RxmsgPool );
	MsgSetClose( &sess->CtrlMsgPool );
	MsgSetClose( &sess->TxmsgStreamPool );

	// Free the socket.
	if ( sess->socket != INVALID_SOCKET_HANDLE )
		osdSocketDestroy( sess->socket );

	free( sess->logbuf );	// Free log buffer.

	// Free session object, but first mark it Invalid in case some errant thread tries to use it after it has been destroyed.
	sess->signature = SESSION_SIGNATURE_INVALID;
	free( sess );
}

////////////////////////////////////////////////////////////////////////////////
// API. Create a session object and connect it to an I/O server remote shell.
// Imports:
//  svrIpAddr	- 24xx IP address, expressed as asciiz string.
//	svrPort		- 24xx telnet port number.
//	LogbufSize	- char capacity of debug log buffer -- set to NULL if logging will not be used.
//	sess		- new, uninitialized session to be opened.
// Returns error code.

static S24XXERR SessionOpenHelper( const char *svrIpAddr, u16 svrPort, u32 LogbufSize, SESSION *sess, u32 MaxConnectMsec )
{
	S24XXERR	err;
	int			rsplen;






//	osdDebugPrint( "debug message\n" );





	// Create log buffer ------------------------------------------------

	// If log buffer is needed ...
	if ( LogbufSize > 0 )
	{
		if ( ( LogbufSize & ( LogbufSize - 1 ) ) != 0 )	// If log buffer size is not power of 2 ...
		{
			LogbufSize |= (LogbufSize >> 1);				// Force buffer size to be a power of 2.
			LogbufSize |= (LogbufSize >> 2);
			LogbufSize |= (LogbufSize >> 4);
			LogbufSize |= (LogbufSize >> 8);
			LogbufSize |= (LogbufSize >> 16);
			LogbufSize++;
		}

		sess->logbuf = malloc( LogbufSize );			// Create debug log buffer.
		if ( sess->logbuf == NULL )						// Abort if log buffer couldn't be created.
			return ERR_MALLOC;

		sess->logbufSize = LogbufSize;
	}

	// Create MSG objects and pools --------------------------------------------

	// Create the tx and rx MSG objects and their fifos and pools. Pools are linked lists of uncommitted objects that
	// can be used to allocate or free objects as needed; objects may be inserted or removed from arbitrary list
	// positions. Fifos are ordered linked lists; objects are inserted at the list tail and removed from the head.

	// Create MSG pool used for rx stream data.
	if ( ( err = MsgSetOpen( &sess->RxmsgPool, TRUE, NUM_RXMSG_OBJECTS, 1024 ) ) != ERR_NONE )
		return err;
	sess->RxmsgPool.hiwater				= RXMSGPOOL_HIWATER;		// Install watermark levels and handler.
	sess->RxmsgPool.lowater				= RXMSGPOOL_LOWATER;
	sess->RxmsgPool.watermarkHandler	= RxpoolWatermarkHandler;

	// Create the MSG object pool used for non-stream messages.
	if ( ( err = MsgSetOpen( &sess->CtrlMsgPool, FALSE, NUM_TXMSG_NONSTREAM_OBJECTS, 1024 ) ) != ERR_NONE )
		return err;

	// Create the tx MSG object pool used for sending stream data and cpc commands. Only one object is in the pool, to guarantee that
	// only one tx stream chunk will be in play at a time.
	if ( ( err = MsgSetOpen( &sess->TxmsgStreamPool, TRUE, 1, 1024 ) ) != ERR_NONE )
		return err;

	// Allocate an initial MSG object from the rx free pool, which will be used to accumulate rx stream data.
	// This is freed when the session is closed, so no need to free it when this thread terminates. This is
	// guaranteed to succeed since RxmsgPool was successfully created and stocked with MSG objects.
	sess->RxmsgCurrent = RxmsgAlloc( sess, MSGTYPE_STREAM );

	// Create MSG fifos --------------------------------------------

	if ( ( err = MsgSetOpen( &sess->RxmsgFifo, TRUE, 0, 1024 ) ) != ERR_NONE )
		return err;
	if ( ( err = MsgSetOpen( &sess->TxmsgFifo, TRUE, 0, 1024 ) ) != ERR_NONE )
		return err;
	if ( ( err = MsgSetOpen( &sess->RxCpcReplyFifo, TRUE, 0, 1024 ) ) != ERR_NONE )
		return err;

	// Create session-level thread synchronization objects -------------------------

	if ( ( sess->ReadMutex = osdMutexCreate() ) == NULL )
		return ERR_CREATEMUTEX;
	if ( ( sess->critsectTelnet = osdCriticalSectionCreate() ) == NULL )
		return ERR_CRITSECTCREATE;
	if ( ( sess->critsectShell = osdCriticalSectionCreate() ) == NULL )
		return ERR_CRITSECTCREATE;

	// Create socket and connect it ---------------------------------

	if ( ( sess->socket = osdSocketCreate() ) == INVALID_SOCKET_HANDLE )					// Create socket and attach to session; abort if failed.
		return ERR_SOCKETCREATE;

	if ( ( err = osdSocketConnect( sess->socket, svrIpAddr, svrPort, MaxConnectMsec ) ) == 0 )		// Connect session's socket to telnet server; abort if failed.
		return ERR_SESSIONCONNECT;

	// Create threads ----------------------------------------------------

	// Create thread that receives, demultiplexes, and telnet parses all incoming data from server. This is
	// set to higher priority to enable incoming flow control messages to be quickly processed.
	if ( ( sess->RxPacketizerThread = osdThreadCreate( RxPacketizerThread, sess, TRUE ) ) == NULL )
		return ERR_THREADCREATE;

	if ( ( sess->TxSerializerThread = osdThreadCreate( TxSerializerThread, sess, FALSE ) ) == NULL )
		return ERR_THREADCREATE;

	// Open remote shell and sync to it -------------------------------------

	// Fetch received app data, which should be the beginning of, or a completed, shell signon message. Abort if we don't receive any part of a shell signon message.
	if ( ( rsplen = SessionStreamRead( sess, &err, (char*)sess->appbuf, SESSION_BUFSIZE, TRUE ) ) <= 0 )
		return ERR_OPENSHELL;

	// Repeat until shell prompt is received:
	while ( sess->appbuf[rsplen - 1] != '>' )
	{
		// Fetch next chunk of received text (either signon message or "no sessions available" message). Abort if no more text was received.
		if ( ( rsplen = SessionStreamRead( sess, &err, (char*)sess->appbuf, SESSION_BUFSIZE, TRUE ) ) == 0 )
			return ERR_TOOMANYSESSIONS;
	}

	sess->isLoggedIn = TRUE;	// We are online to the remote shell.

	return ERR_NONE;			// success
}

// Public API.
BOOL SessionOpen( SESSION **psess, S24XXERR *err, u16 svrModel, const char *svrIpAddr, u16 svrPort, u32 MaxConnectMsec, u32 LogbufSize )
{
	SESSION *sess;

	// Abort if error already pending.
	if ( *err != ERR_NONE )
		sess = NULL;

	else
	{
		// Create session object; abort if failed.
		sess = malloc( sizeof(SESSION) );
		if ( sess == NULL )
			*err = ERR_MALLOC;

		else	// Initialize session object ------------------------------------
		{
			// Clear all fields so we will be able to determine later what resources have been created/allocated.
			memset( sess, 0, sizeof(SESSION) );

			// Init non-zero fields.
			sess->svrModel				= svrModel;					// I/O server model number.
			sess->socket				= INVALID_SOCKET_HANDLE;	// No socket has been created for this session.

			// For all MSG pools and fifos, reference this session as the owner.
			sess->CtrlMsgPool.sess		= sess;
			sess->RxmsgPool.sess		= sess;
			sess->TxmsgStreamPool.sess	= sess;
			sess->TxmsgFifo.sess		= sess;
			sess->RxmsgFifo.sess		= sess;
			sess->RxCpcReplyFifo.sess	= sess;

			// Allocate resources and attach them to the session, and connect session to 24xx remote shell.
			*err = SessionOpenHelper( svrIpAddr, svrPort, LogbufSize, sess, MaxConnectMsec );

			// Shut down the session and free it if there was a problem, otherwise mark it Valid.
			if ( *err != ERR_NONE )
			{
				SessionClose( sess );
				sess = NULL;
			}
			else
				sess->signature = SESSION_SIGNATURE_VALID;	// mark session valid
		}
	}

	*psess = sess;						// return session handle
	return ( *err == ERR_NONE );		// indicate success/fail
}
