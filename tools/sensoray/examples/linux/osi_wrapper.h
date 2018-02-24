///////////////////////////////////////////////////////////////////////////////////////
// File			: osi_wrapper.h
// Function     : API internal includes and wrappers that conceal OS dependencies
// Target       : OS independent
// Author		: Jim L
// Copyright	: Copyright (C) 2010 Sensoray
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _OSI_WRAPPER_H_
#define _OSI_WRAPPER_H_

#include "stypes.h"

// Network -------------------------------------------------

#define INVALID_SOCKET_HANDLE	0

typedef unsigned int SOCKET;		// Handle to network socket.

typedef enum SOCKWAIT_RESULT {		// Returned value from socketWaitRd():
	SOCKET_RECV_OOB,				//  Out-of-band data.
	SOCKET_RECV_INBAND,				//  Application data.
	SOCKET_RECV_TIMEOUT,			//  Timeout.
	SOCKET_RECV_ERROR				//  Error.
} SOCKWAIT_RESULT;

// Functions in osd_netlayer.c:
BOOL			osdSocketIfOpen		( void );														// Initialize the socket interface.
void			osdSocketIfClose	( void );														// Shutdown the socket interface.
SOCKET			osdSocketCreate		( void );														// Create a socket.
void			osdSocketDestroy	( SOCKET s );													// Destroy socket and free its resources.
BOOL			osdSocketConnect	( SOCKET s, const char *svrIpAddr, u16 svrPort, uint msec );	// Connect socket to a Sensoray i/o server.
void			osdSocketDisconnect	( SOCKET s );													// Close the connection to a Sensoray i/o server.
int				osdSocketRecv		( SOCKET s, char *buf, int len, BOOL oob );						// Wait for and then fetch received data from a socket. Priority is given to oob data.
SOCKWAIT_RESULT	osdSocketWaitRd		( SOCKET s, uint msec );										// Wait for socket data/exception/timeout, whichever comes first.
int				osdSocketWrite		( SOCKET s, const char* data, int len );						// Send data to the server.

void			osdDebugPrint		( const char *msg );

// Mutexes ------------------------------------------------

typedef void	*MUTEX;			// Handle to mutex.

MUTEX			osdMutexCreate		( void );
void			osdMutexDestroy		( MUTEX m );
BOOL			osdMutexPend		( MUTEX m, BOOL wait );
void			osdMutexPost		( MUTEX m );

// Semaphores -----------------------------------------------

typedef void	*SEMAPHORE;

SEMAPHORE		osdSemaphoreCreate	( u32 InitialCount, u32 MaxCount );
void			osdSemaphoreDestroy	( SEMAPHORE s );
BOOL			osdSemaphorePend	( SEMAPHORE s, BOOL wait );
void			osdSemaphorePost	( SEMAPHORE s );

// Critical sections ----------------------------------------

typedef void	*CRITSECT;		// Handle to critical section (which may be a mutex, depending on os-dependent implementation).

CRITSECT		osdCriticalSectionCreate	( void );
void			osdCriticalSectionDestroy	( CRITSECT cs );
void			osdCriticalSectionEnter		( CRITSECT cs );
void			osdCriticalSectionLeave		( CRITSECT cs );

// Threads ---------------------------------------------------

typedef void	*THREAD;		// Handle to thread.

// Functions in osd_thread.h:
THREAD			osdThreadCreate			( THREAD threadFunc, void *threadArg, BOOL highPriority );
void			osdThreadSleep			( u32 msec );
void			osdThreadWaitTerminate	( THREAD );

// Time ------------------------------------------------------

// Functions in osd_time.c:
double			osdCurrentTime		( void );
double			osdElapsedTime		( double tstart );

#endif // _OSI_WRAPPER_H_
