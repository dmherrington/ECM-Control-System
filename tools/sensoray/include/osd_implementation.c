///////////////////////////////////////////////////////////////////////////////////////
// File			: osd_implementation.c
// Function		: OS-dependent implementation for Sensoray model 24xx i/o clients
// Target		: Linux
// Author		: Jim L
// Copyright	: Copyright (C) 2008 Sensoray
///////////////////////////////////////////////////////////////////////////////////////


#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define __USE_UNIX98

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>





typedef const struct sockaddr SOCKADDR;
#define INVALID_SOCKET	-1



#include "stypes.h"


#include "osi_wrapper.h"		// forward declarations





///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  THREAD FUNCTIONS  //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////





	
////////////////////////////////////////////////////////////////////////////////////////////////////
// Create thread. The threadFunc must have this prototype: DWORD ThreadProc( void *lpParameter );
// This version ignores highPriority -- must implement if this is a problem.

THREAD osdThreadCreate( void *threadFunc, void *threadArg, BOOL highPriority )
{
	pthread_t thread;
	
	if ( pthread_create( &thread, NULL, threadFunc, threadArg ) != 0 )	// 0 == success
	{
		perror( "pthread_create" );
		return NULL;
    }
	return (THREAD)thread;
}










/*

// CODE FROM ANOTHER PROJECT THAT DEMONSTRATES PTHREAD PRIORITY:


#define IMAGE_THREAD_PRIORITY   sched_get_priority_max(SCHED_FIFO) - 1	// low prio
#define CAPTURE_THREAD_PRIORITY sched_get_priority_max(SCHED_FIFO)		// high prio

	struct sched_param  schedParam;
	pthread_attr_t      attr;

	// Set the priority of this whole process to max (requires root)
	setpriority(PRIO_PROCESS, 0, -20);

	// Initialize the thread attributes
	if ( pthread_attr_init( &attr ) )
	{
		ERR("Failed to initialize thread attrs\n");
		cleanup(EXIT_FAILURE);
	}

	// Force the thread to use custom scheduling attributes
	if ( pthread_attr_setinheritsched( &attr, PTHREAD_EXPLICIT_SCHED ) )
	{
		ERR("Failed to set schedule inheritance attribute\n");
		cleanup(EXIT_FAILURE);
	}

	// Set the thread to be fifo real time scheduled
	if ( pthread_attr_setschedpolicy( &attr, SCHED_FIFO ) )
	{
		ERR("Failed to set FIFO scheduling policy\n");
		cleanup(EXIT_FAILURE);
	}

	// Set thread priority
	schedParam.sched_priority = VIDEO_THREAD_PRIORITY;
	if (pthread_attr_setschedparam(&attr, &schedParam)) {
			ERR("Failed to set scheduler parameters\n");
			cleanup(EXIT_FAILURE);
	}

	// Create thread
	if (pthread_create(&s2253.videoThread, &attr, videoThrFxn, &s2253.videoEnv)) {
		ERR("Failed to create video thread\n");
		cleanup(EXIT_FAILURE);
	}


*/









////////////////////////////////////////////////////////////////////////////
// Wait for a thread to terminate.

void osdThreadWaitTerminate( THREAD t )
{
	pthread_join( (pthread_t)t, NULL );
}

/////////////////////////////////////////////////////////////
// Suspend current thread for specified milliseconds.

void osdThreadSleep( u32 msec )
{
	sleep( msec );
}


///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  MUTEX FUNCTIONS  ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////
// Create mutex, initially signaled.

MUTEX osdMutexCreate( void )
{
	pthread_mutex_t		*m;
	pthread_mutexattr_t	attr;

	// Allocate storage for mutex.
	m = (pthread_mutex_t*)malloc( sizeof( pthread_mutex_t ) );

	// If mutex object successfully created ...
	if ( m )
	{
		// Configure mutex attributes so it will allow nested pends.
		pthread_mutexattr_init( &attr );
		pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE );

		// Create the mutex.
		pthread_mutex_init( m, &attr );

		// Attributes no longer needed.
		pthread_mutexattr_destroy( &attr );
	}

	// Return handle to the mutex.
	return (MUTEX)m;
}

void osdMutexDestroy( MUTEX m )
{
	pthread_mutex_destroy( (pthread_mutex_t*)m );
}


/////////////////////////////////////////////////////
// Wait for mutex to be signaled or error.
// Returns TRUE if signaled.

BOOL osdMutexPend( MUTEX m, BOOL wait )
{
	int status = wait ? pthread_mutex_lock( (pthread_mutex_t*)m ) : pthread_mutex_trylock( (pthread_mutex_t*)m );

	switch ( status )
	{
	case 0:				// Mutex is acquired. 
		return TRUE;
	default:			// Not acquired, for any reason.
		return FALSE;
	}
}

void osdMutexPost( MUTEX m )
{
	pthread_mutex_unlock( (pthread_mutex_t*)m );
}



///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////  CRITICAL SECTIONS  //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// Create critical section object and return its handle.
// Returns zero upon fail.

CRITSECT osdCriticalSectionCreate( void )
{
	return (CRITSECT)osdMutexCreate();
}

///////////////////////////////////////////////////
// Destroy critical section access control object.

void osdCriticalSectionDestroy( CRITSECT cs )
{
	osdMutexDestroy( (MUTEX)cs );
}

///////////////////////////////////////////////
// Begin critical section.

void osdCriticalSectionEnter( CRITSECT cs )
{
	osdMutexPend( (MUTEX)cs, TRUE );
}

/////////////////////////////////////////
// Leave critical section.

void osdCriticalSectionLeave( CRITSECT cs )
{
	pthread_mutex_unlock( (MUTEX)cs );
}



///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  SEMAPHORE FUNCTIONS  /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


SEMAPHORE osdSemaphoreCreate( u32 InitialCount, u32 MaxCount )
{
	// Allocate storage for semaphore.
	sem_t *s = (sem_t*)malloc( sizeof( sem_t ) );

	// Initialize the semaphore if it was successfully created.
	if ( s )
		sem_init( s, 0, InitialCount );

	// Return handle to the mutex.
	return (SEMAPHORE)s;
}

void osdSemaphoreDestroy( SEMAPHORE s )
{
	sem_destroy( (sem_t*)s );
}


/////////////////////////////////////////////////////
// Wait for mutex to be signaled or error.
// Returns TRUE if signaled.

BOOL osdSemaphorePend( SEMAPHORE s, BOOL wait )
{
	int status = wait ? sem_wait( (sem_t*)s ) : sem_trywait( (sem_t*)s );

	switch ( status )
	{
	case 0:				// Semaphore is signaled. 
		return TRUE;
	default:			// Unsignaled or error.
		return FALSE;
	}
}

void osdSemaphorePost( SEMAPHORE s )
{
	sem_post( (sem_t*)s );
}


///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////  TIME FUNCTIONS  ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////
// Return current system time.

double osdCurrentTime( void )
{
	struct timeval t;
	gettimeofday( &t , NULL );
	return (double)t.tv_sec + (double)t.tv_usec / 1000000.0;
}

///////////////////////////////////
// Return elapsed system time.

double osdElapsedTime( double tstart )
{
	double tend = osdCurrentTime();
	return tend - tstart;
}


///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  NETWORK FUNCTIONS  /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////
// Open socket interface.
// Returns TRUE if successful, else FALSE.

BOOL osdSocketIfOpen( void )
{
	return 1;	// Not needed on Linux
}

////////////////////////////////////////////
// Close socket interface.

void osdSocketIfClose( void )
{
	// Not needed on Linux
}

///////////////////////////////////////////////
// Create socket and return handle to it.

SOCKET osdSocketCreate( void )
{
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );			// Attempt to create a socket.
	return ( s == INVALID_SOCKET ) ? INVALID_SOCKET_HANDLE : s;		// Return socket handle, or NULL if failed.
}

/////////////////////////////////////////////////////////////////
// Bind socket and connect it to telnet service.
// Imports:
//	s			- socket that is to be bound
//	svrIpAddr	- asciiz ip dot address of server
//	svrPort		- server port to use; set to 23 for standard telnet port
//	msec		- maximum time, in milliseconds, for connection to activate

BOOL osdSocketConnect( SOCKET s, const char *svrIpAddr, u16 svrPort, uint msec )
{
	u_long				nonBlocking	= TRUE;
	fd_set				wrSet;
	struct timeval		t;
	struct sockaddr_in	sa;
	
	// Set up connection attributes.
	sa.sin_family		= AF_INET;					// Use ip.
	sa.sin_addr.s_addr	= inet_addr( svrIpAddr );	// Convert ip dot address to numeric.
	sa.sin_port			= htons( svrPort );			// Connect to server's telnet service.

	// Make socket non-blocking so we can timeout the connection.
	ioctl( s, FIONBIO, &nonBlocking );

	// Initiate the connection.
	connect( s, (SOCKADDR *)&sa, sizeof(sa) );

	// Specify max time to wait for connection.
	t.tv_sec	= msec / 1000;
	t.tv_usec	= 1000 * ( msec - ( t.tv_sec * 1000 ) );

	// Wait for connection (i.e., writeable socket) or timeout, whichever comes first.
	FD_ZERO( &wrSet );
	FD_SET( s, &wrSet );
	select( 0, NULL, &wrSet, NULL, &t );

	// Make socket blocking.
	nonBlocking = FALSE;
	ioctl( s, FIONBIO, &nonBlocking );

	// Return TRUE iff connected.
	return FD_ISSET( s, &wrSet );
}




///////////////////////////////////////////////////////
// Break socket connection.

void osdSocketDisconnect( SOCKET s )
{
	shutdown( s, SHUT_RDWR );
}

/////////////////////////////////////////////
// Close a socket and free its resources.

void osdSocketDestroy( SOCKET s )
{
	close( s );		// Close socket.
}

////////////////////////////////////////////////////////
// Queue some data to be written to the remote end.
// Return number of bytes written.

int osdSocketWrite( SOCKET s, const char* buf, int len )
{
	return send( s, buf, len, 0 );
}

///////////////////////////////////////////////////////
// Wait for socket to have exception or receive data.
// Imports:
//  s		- socket handle.
//  msec	- max milliseconds to wait for data. Set to ~0 for infinite wait.
// Returns: 0 (no data available) | SOCKET_RECV_OOB | SOCKET_RECV_INBAND | SOCKET_RECV_TIMEOUT | SOCKET_RECV_ERROR.

SOCKWAIT_RESULT osdSocketWaitRd( SOCKET s, uint msec )
{
	fd_set			readSet;
	fd_set			exceptSet;
	struct timeval	t;
	struct timeval	*pt;
	int				selrtn;

	FD_ZERO( &readSet );							// Wait for socket event.
	FD_ZERO( &exceptSet );
	FD_SET( s, &readSet );
	FD_SET( s, &exceptSet );
	
	if ( msec != ~0 )
	{
		t.tv_sec	= msec / 1000;
		t.tv_usec	= 1000 * ( msec - ( t.tv_sec * 1000 ) );
		pt = &t;
	}
	else
		pt = NULL;

	selrtn = select( s + 1, &readSet, NULL, &exceptSet, pt );

	if ( ( selrtn == 0 ) && ( msec != ~0 ) )
		return SOCKET_RECV_TIMEOUT;			// Socket timed out.

	if ( selrtn == -1 )
		return SOCKET_RECV_ERROR;			// Socket error raised.

	if ( FD_ISSET( s, &exceptSet ) )
		return SOCKET_RECV_OOB;				// Out-of-band data is available.

	if ( FD_ISSET( s, &readSet ) )
		return SOCKET_RECV_INBAND;			// In-band data is available, or connection has been closed/reset/terminated.

	return 0;								// No data available.
}

/////////////////////////////////////////////////////////////////////
// Read data into buf and return data size.
// Imports:
//	oob - TRUE for oob data, FALSE for inband data.

int osdSocketRecv( SOCKET s, char *buf, int len, BOOL oob )
{
	len = recv( s, buf, len, oob ? MSG_OOB : 0 );
	if ( len < 0 )
		len = 0;		// force data size to zero upon socket error
	return len;
}

