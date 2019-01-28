//////////////////////////////////////////////////////////////////////////////////////////////////
//  
// ACS Motion Control Ltd.
// Copyright © 1999 - 2013. All Rights Reserved.
//
// FILE		:	 immediate.cpp
//
// OVERVIEW
// ========
//
// The sample Win32 console application demonstrates the usage of the ACSC Library functions.  
//
// The sample shows how to open communication with the simulator or with the controller
// (via serial, ethernet or PCI bus) and how to send immediate commands.
//
// The sample executes a reciprocated point-to-point motion.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <conio.h>
#include <stdio.h>
#include "windows.h"
#include "..\..\..\ACSC.h"

HANDLE hComm;					 // communication handle

void ErrorsHandler(const char* ErrorMessage, BOOL fCloseComm)
{
	printf (ErrorMessage);
	printf ("press any key to exit.\n");
	if (fCloseComm) acsc_CloseComm(hComm);
	_getch();
};

int main(int argc, char *argv[])
{
	double FPOS;
	int State;
	
	printf ("ACS Motion Control Ltd. Copyright © 1999 - 2013. All Rights Reserved.\n");
    printf ("Application executes reciprocated point-to-point motion\n");

	/*****************************************************************/
	// Open communication with the simulator
	printf ("Application opens communication with the simulator and\n");
	printf ("sends some commands to the simulator using ACSC Library functions\n\n"); 

	printf ("Wait for opening of communication with the simulator... \n"); 

	hComm = acsc_OpenCommDirect();
	if (hComm == ACSC_INVALID)
	{
		ErrorsHandler("error while opening communication.\n", FALSE);
		return -1;
	}
	printf ("Communication with the simulator was established successfully!\n"); 
	/*****************************************************************/
	/*********************************************************************
	// Example of opening communication with the controller via COM1
	printf ("Application opens communication with the controller via serial link and\n");
	printf ("sends some commands to the controller using ACSC Library functions\n\n"); 

	printf ("Wait for opening of communication with the controller... \n"); 

	hComm = acsc_OpenCommSerial(1, 115200);
	if (hComm == ACSC_INVALID)
	{
		ErrorsHandler("error while opening communication.\n", FALSE);
		return -1;
	}
	printf ("Communication with the controller was established successfully!\n"); 
	/*****************************************************************/
	/*********************************************************************
	// Example of opening communication with the controller via Ethernet
	printf ("Application opens communication with the controller via ethernet and\n");
	printf ("sends some commands to the controller using ACSC Library functions\n\n"); 

	printf ("Wait for opening of communication with the controller... \n"); 

    // 10.0.0.100 - default IP address of the controller
	// for the point to point connection to the controller
	hComm = acsc_OpenCommEthernet("10.0.0.100", ACSC_SOCKET_DGRAM_PORT);
	// for the connection to the controller via local network or Internet
//	hComm = acsc_OpenCommEthernet("10.0.0.100", ACSC_SOCKET_STREAM_PORT);
	if (hComm == ACSC_INVALID)
	{
		ErrorsHandler("error while opening communication.\n", FALSE);
		return -1;
	}
	printf ("Communication with the controller was established successfully!\n"); 
	/*********************************************************************/
	/*********************************************************************
	// Open communication with the controller via PCI bus (for the SPiiPlus PCI-8 series only)
	printf ("Application opens communication with the controller and\n");
	printf ("sends some commands to the controller using ACSC Library functions\n\n"); 

	printf ("Wait for opening of communication with the controller... \n"); 

	hComm = acsc_OpenCommPCI(ACSC_NONE);
	if (hComm == ACSC_INVALID)
	{
		ErrorsHandler("error while opening communication.\n", FALSE);
		return -1;
	}
	printf ("Communication with the controller was established successfully!\n"); 
	/*****************************************************************/
    
	printf ("Press any key to run motion.\n");
    printf ("Then press any key to exit.\n");

	_getch();

	// Enable the motor X
	if (!acsc_Enable(hComm, ACSC_AXIS_X, NULL))
	{
		ErrorsHandler("transaction error.\n", TRUE);
		return -1;
	}
    printf ("Motor enabled\n");

	Sleep(1000);

    while (!_kbhit())
	{
		// execute point-to-point motion to position 4000
		if (!acsc_ToPoint(hComm, 0, ACSC_AXIS_X, 4000, NULL))
		{
			ErrorsHandler("PTP motion error %d.\n", TRUE);
			return -1;
		}
	    printf ("Moving to the position 4000...\n");

		// execute backward point-to-point motion to position 0
		if (!acsc_ToPoint(hComm, 0, ACSC_AXIS_X, 0, NULL))
		{
			ErrorsHandler("PTP motion error.\n", TRUE);
			return -1;
		}
	    printf ("Moving back to the position 0...\n");

		// Check if both of motions finished
		do
		{
			if (acsc_GetFPosition(hComm, ACSC_AXIS_X, &FPOS, NULL))
			{
				printf ("%f\r", FPOS);
			}

			// Read the motor X state. Fifth bit shows motion process 
			if (!acsc_GetMotorState(hComm, ACSC_AXIS_X, &State, NULL))
			{
				ErrorsHandler("get motor state error.\n", TRUE);
				return -1;
			}

			Sleep(500);

		} while (State & ACSC_MST_MOVE);
	}

	acsc_CloseComm(hComm);

	return 0;
}
