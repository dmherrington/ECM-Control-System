////////////////////////////////////////////////////////////////////////////////
// File			: netlayer.c
// Function		: OS-dependent network interface for Sensoray 2426
// Target		: Linux
// Author		: Jim Lamberson
//				: Pete Eberlein
// Created		: 2008/05/19
// Modified		: 2008/10/27
// Copyright	: Copyright (C) 2008 Sensoray
////////////////////////////////////////////////////////////////////////////////

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <unistd.h>

#include "netlayer.h"

#define PORT_TELNET		23

typedef const struct sockaddr SOCKADDR;
#define INVALID_SOCKET	-1

////////////////////////////////////////////
// Open socket interface.
// Returns TRUE if successful, else FALSE.

BOOL socketIfOpen( void )
{
	// Not needed on Linux
	return 1;
}

////////////////////////////////////////////
// Close socket interface.

void socketIfClose( void )
{
	// Not needed on Linux
}

///////////////////////////////////////////////
// Create socket and return handle to it.

SOCKET socketCreate( void )
{
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );			// Attempt to create a socket.
	return ( s == INVALID_SOCKET ) ? INVALID_SOCKET_HANDLE : s;		// Return socket handle, or NULL if failed.
}

/////////////////////////////////////////////////////////////////
// Bind socket and connect it to telnet service.

BOOL socketConnect( SOCKET s, const char *svrIpAddr, unsigned int msec )
{
	u_long				nonBlocking	= TRUE;
	fd_set		wrSet;
	struct timeval		t;
	struct sockaddr_in	sa;
	
	// Set up connection attributes.
	sa.sin_family		= AF_INET;					// Use ip.
	sa.sin_addr.s_addr	= inet_addr( svrIpAddr );	// Convert ip dot address to numeric.
	sa.sin_port			= htons( PORT_TELNET );		// Connect to server's telnet service.

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

void socketDisconnect( SOCKET s )
{
	shutdown( s, SHUT_RDWR );
}

/////////////////////////////////////////////
// Close a socket and free its resources.

void socketDestroy( SOCKET s )
{
	close( s );		// Close socket.
}

////////////////////////////////////////////////////////
// Queue some data to be written to the remote end.
// Return number of bytes written.

int socketWrite( SOCKET s, const char* buf, int len )
{
	return send( s, buf, len, 0 );
}

///////////////////////////////////////////////////////
// Wait for socket to have exception or receive data.
// Returns: SOCKET_RECV_OOB | SOCKET_RECV_INBAND | SOCKET_TIMEOUT.

SOCKWAIT_RESULT socketWaitRd( SOCKET s, unsigned int msec )
{
	fd_set	readSet;
	fd_set	exceptSet;
	struct timeval	t;

	FD_ZERO( &readSet );							// Wait for socket to become readable or error.
	FD_ZERO( &exceptSet );
	FD_SET( s, &readSet );
	FD_SET( s, &exceptSet );
	
	t.tv_sec	= msec / 1000;
	t.tv_usec	= 1000 * ( msec - ( t.tv_sec * 1000 ) );

	select( s+1, &readSet, NULL, &exceptSet, &t );

	if ( FD_ISSET( s, &exceptSet ) )				// If oob data is available ...
		return SOCKET_RECV_OOB;

	if ( FD_ISSET( s, &readSet ) )					// If in-band data is available ...
		return SOCKET_RECV_INBAND;

	return SOCKET_RECV_TIMEOUT;
}

/////////////////////////////////////////////////////////////////////
// Read data into buf and return data size.
// Imports:
//	oob - TRUE for oob data, FALSE for inband data.

int socketRecv( SOCKET s, char *buf, int len, BOOL oob )
{
	int flags = oob ? MSG_OOB : 0;
	len = recv( s, buf, len, flags );
	return len;
}
