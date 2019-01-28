// ACSCTermDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ACSCTerm.h"
#include "ACSCTermDlg.h"
#include "CommunicationDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT TermThreadProc( LPVOID pParam )
{
    CACSCTermDlg* pObject = (CACSCTermDlg *)pParam;
	return pObject->TerminalThread(); 	
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACSCTermDlg dialog

CACSCTermDlg::CACSCTermDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CACSCTermDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CACSCTermDlg)
	m_ConnectionString = _T("Communication: OFF");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	CommSet.CommType = 0;
	CommSet.Handle = ACSC_INVALID;
	CommSet.ConnectionString = m_ConnectionString;
	CommSet.SerialPort = 0;					//COM1
	CommSet.SerialRate = 7;					//115200
	CommSet.EthernetAddress = "10.0.0.100"; //default address
	CommSet.EthernetConnection = 1;			//Internet/Intranet
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_fStopTermThread = FALSE;
	m_fConnect = TRUE;
	m_pWinThread = NULL;
	m_nEditPos = 0;
}

void CACSCTermDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CACSCTermDlg)
	DDX_Control(pDX, IDC_EDIT1, m_editTerminal);
	DDX_Control(pDX, IDC_SENDCOMBO, m_comboSend);
	DDX_Text(pDX, IDC_CONNECTIONSTATIC, m_ConnectionString);
	DDV_MaxChars(pDX, m_ConnectionString, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CACSCTermDlg, CDialog)
	//{{AFX_MSG_MAP(CACSCTermDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECTBUTTON, OnConnect)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(ID_CLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CACSCTermDlg message handlers

BOOL CACSCTermDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	CFont* pFont = new CFont();
	pFont->CreatePointFont(80, "Courier New");
	m_editTerminal.SetFont(pFont);

	GetDlgItem(IDC_CONNECTBUTTON)->SetFocus();
//	return TRUE;  // return TRUE  unless you set the focus to a control
	return FALSE;
}

void CACSCTermDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CACSCTermDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CACSCTermDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CACSCTermDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	if (m_fConnect) //connect
	{
		// create communication dialog and run it
		// the structure CommSet contains last saved communication setting
		// or default settings for the first startup 
		CCommunicationDialog commDlg(CommSet);
		commDlg.DoModal();
		// save communication settings to the structure CommSet
		commDlg.GetCommSettings(&CommSet);
		m_ConnectionString = CommSet.ConnectionString;
		if (CommSet.Handle != ACSC_INVALID)
		{
			m_fConnect = FALSE;
			// run communication history thread
			RunTermThread();
			CString Caption("Disconnect");
			GetDlgItem(IDC_CONNECTBUTTON)->SetWindowText(Caption);
			m_comboSend.SetFocus();
		}
	}
	else			//disconnect
	{
		m_fConnect = TRUE;
		m_ConnectionString = "Communication: OFF";
		CString Caption("Connect");
		GetDlgItem(IDC_CONNECTBUTTON)->SetWindowText(Caption);
		GetDlgItem(IDC_CONNECTBUTTON)->SetFocus();
		// stop communication history thread
		StopTermThread();
		// close history buffer
		acsc_CloseHistoryBuffer(CommSet.Handle);
		// close communication handle
		acsc_CloseComm(CommSet.Handle);
		CommSet.Handle = ACSC_INVALID;
	}
	UpdateData(FALSE);
}

void CACSCTermDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	// function sends command to the controller
	CString m_strCommand;
	m_comboSend.GetWindowText(m_strCommand);
	int ind = m_comboSend.FindStringExact(-1, m_strCommand);
	if (ind != CB_ERR) m_comboSend.DeleteString(ind);
	m_comboSend.InsertString(0, m_strCommand);
	// every sent command should be concluded by '\r' character
	m_strCommand += '\r';
	// send command to the controller
	if (!acsc_Send(CommSet.Handle, (char *)LPCTSTR(m_strCommand), m_strCommand.GetLength(), NULL))
	{
		char str1[300], str2[256];
		int Received;
		// retrieve last error
		acsc_GetErrorString(CommSet.Handle, acsc_GetLastError(), str2, 256, &Received);
		str2[Received] = '\0';
		sprintf(str1, "Error: %s", str2);
		MessageBox(str1, "ACSC Terminal", MB_ICONWARNING);
	}
	m_comboSend.SetEditSel(0, -1);
}

void CACSCTermDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	StopTermThread();
	acsc_CloseHistoryBuffer(CommSet.Handle);
	acsc_CloseComm(CommSet.Handle);
	CDialog::OnCancel();
}

void CACSCTermDlg::OnOK() 
{
	// TODO: Add extra validation here
//	CDialog::OnOK();
}

void CACSCTermDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
//	CDialog::OnCancel();
}

UINT CACSCTermDlg::TerminalThread()
{
	// every 100 ms communication history is updated
	int Received;
	while (!m_fStopTermThread)
	{
		// get all communication history
		if (acsc_GetHistory(CommSet.Handle, m_HistBuf, HISTBUF_SIZE - 1, &Received, TRUE))
		{
			if (Received > 0)
			{
				m_HistBuf[Received] = '\0';
				// insert '\n' after each line
				FormatBuffer();
				// show communication history
				m_editTerminal.SetWindowText(m_EditBuf);
				int lines = m_editTerminal.GetLineCount();
				m_editTerminal.LineScroll(lines); 
			}
		}
		Sleep(100);
	}
	return 0;
}

void CACSCTermDlg::RunTermThread()
{
	m_fStopTermThread = FALSE;
	m_pWinThread = AfxBeginThread(TermThreadProc, this);
	m_pWinThread->m_bAutoDelete = FALSE;
}

void CACSCTermDlg::StopTermThread()
{
	if (m_pWinThread)
	{
		m_fStopTermThread = TRUE;
		WaitForSingleObject(m_pWinThread->m_hThread, 10000);
		delete m_pWinThread;
		m_pWinThread = NULL;
	}
}

void CACSCTermDlg::FormatBuffer()
{
	// each line of the controller replies are concluded by '\r'
	// function adds '\n' in the end of the lines after '\r'
	char tmpbuf[2*HISTBUF_SIZE];
	int hbuf_pos = 0;
	int tmpbuf_pos = 0;
	while (m_HistBuf[hbuf_pos] != '\0')
	{
		tmpbuf[tmpbuf_pos++] = m_HistBuf[hbuf_pos];
		if (m_HistBuf[hbuf_pos] == '\r')
			tmpbuf[tmpbuf_pos++] = '\n';
		hbuf_pos++;
	}
	tmpbuf[tmpbuf_pos] = '\0';
	if (EDITBUF_SIZE - m_nEditPos < tmpbuf_pos)
	{
		int shortage = tmpbuf_pos - (HISTBUF_SIZE - m_nEditPos);
		m_nEditPos -= shortage;
		memcpy(m_EditBuf, &m_EditBuf[shortage], m_nEditPos);
	}
	strcpy(&m_EditBuf[m_nEditPos], tmpbuf);
	m_nEditPos += tmpbuf_pos;
}
