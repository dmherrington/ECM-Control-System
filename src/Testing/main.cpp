#include <QCoreApplication>

#include <conio.h>

#include "ACSC.h"

#include <cstring>

#define HISTBUF_SIZE	10000
#define EDITBUF_SIZE	100000

//typedef struct {
//    int CommType;				// 0 - serial, 1 - ethernet, 2 - PCI bus, 3 -simulator
//    HANDLE Handle;				// communication handle
//    CString ConnectionString;
//    int SerialPort;
//    int SerialRate;
//    CString EthernetAddress;
//    int EthernetConnection;
//    ACSC_PCI_SLOT PCISlot;
//} COMM_SETTINGS;

HANDLE hComm;

void ErrorsHandler(const char* ErrorMessage, BOOL fCloseComm)
{
    printf("function returned error: %d\n", acsc_GetLastError());
    printf (ErrorMessage);
    printf ("press any key to exit.\n");
    if (fCloseComm) acsc_CloseComm(hComm);
    _getch();
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ACSPL+ program which we download to controller's buffer
    // The program performs a reciprocated motion from position 0 to 4000 and then back
    char* prog = "  enable X \r\n		";

    // Buffer for controller's reply
    double FPOS;

    printf ("ACS Motion Control Ltd. Copyright � 1999 - 2013. All Rights Reserved.\n");
    printf ("Application executes reciprocated point-to-point motion\n");

    /*****************************************************************/
    // Open communication with simulator
    printf ("Application opens communication with the simulator, downloads\n");
    printf ("program to controller's and executes it using ACSC Library functions\n\n");

    printf ("Wait for opening of communication with the simulator... \n");

    hComm = acsc_OpenCommDirect();
    if (hComm == ACSC_INVALID)
    {
        ErrorsHandler("error while opening communication.\n", FALSE);
        return -1;
    }
    printf ("Communication with the simulator was established successfully!\n");
    /*****************************************************************/
    /********************************************************************
    // Example of opening communication with the controller via COM1
    printf ("Application opens communication with the controller via COM1, downloads\n");
    printf ("program to the controller and executes it using ACSC Library functions\n\n");

    printf ("Wait for opening of communication with the controller... \n");

    hComm = acsc_OpenCommSerial(1, 115200);
    if (hComm == ACSC_INVALID)
    {
        ErrorsHandler("error while opening communication.\n", FALSE);
        return -1;
    }
    printf ("Communication with the controller was established successfully!\n");
    /*********************************************************************/
    /*********************************************************************
    // Example of opening communication with controller via Ethernet
    printf ("Application opens communication with the controller via Ethernet, downloads\n");
    printf ("program to the controller and executes it using ACSC Library functions\n\n");

    printf ("Wait for opening of communication with the controller... \n");

    // 10.0.0.100 - default IP address of the controller
    // for the point-to-point connection to the controller
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

    // Stop a program in the buffer 0
    if (!acsc_StopBuffer(hComm, 0, NULL))
    {
        ErrorsHandler("stop program error.\n", TRUE);
        return -1;
    }

    // Download the new program to the controller's buffer
    if (!acsc_LoadBuffer(hComm, 0, prog, (int)strlen(prog), NULL))
    {
        ErrorsHandler("downloading program error.\n", TRUE);
        return -1;
    }
    printf ("Program downloaded\n");

    // Execute the program in the buffer 0
    if (!acsc_RunBuffer(hComm, 0, NULL, NULL))
    {
        ErrorsHandler("run program error.\n", TRUE);
        return -1;
    }

    printf ("Motion is in progress...\n");
    printf ("Feedback position:\n");

    while (!_kbhit())
    {
        // read the feedback position of axis X
        if (acsc_GetFPosition(hComm, ACSC_AXIS_X, &FPOS, NULL))
        {
            printf ("%f\r", FPOS);
        }
        Sleep(500);
    }

    // Stop the program in the buffer 0
    if (!acsc_StopBuffer(hComm, 0, NULL))
    {
        ErrorsHandler("stop program error.\n", TRUE);
        return -1;
    }

    // Close the communication
    acsc_CloseComm(hComm);

    return a.exec();
}
