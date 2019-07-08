//////////////////////////////////////////////////////////////////////////////////////////////////
//  
// ACS Motion Control Ltd.
// Copyright © 1999 - 2013. All Rights Reserved.
//
// FILE		:	 ACSCTerm.cpp
//
// OVERVIEW
// ========
//
// The sample of the communication terminal demonstrates the usage of the ACSC Library functions.  
//
// The sample shows how to open communication with the simulator or with the controller
// (via serial, ethernet or PCI bus) and how to send commands.
// 
// The sample opens the communication history buffer to show all sent to the 
// controller commands and all controller's reaponses.
//
// The communication history buffer is one of the feature of the ACSC Library.
// The library supports storing all messages sent to and received from the controller 
// in a memory buffer. The application can retrieve the full or partial contents of the buffer 
// and also can clear the history buffer.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ACSCTerm.h"
#include "ACSCTermDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CACSCTermApp

BEGIN_MESSAGE_MAP(CACSCTermApp, CWinApp)
	//{{AFX_MSG_MAP(CACSCTermApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACSCTermApp construction

CACSCTermApp::CACSCTermApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CACSCTermApp object

CACSCTermApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CACSCTermApp initialization

BOOL CACSCTermApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CACSCTermDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

