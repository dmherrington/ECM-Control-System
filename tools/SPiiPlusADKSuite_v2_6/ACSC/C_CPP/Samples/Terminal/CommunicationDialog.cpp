// CommunicationDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ACSCTerm.h"
#include "CommunicationDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDialog dialog

CCommunicationDialog::CCommunicationDialog(COMM_SETTINGS& CommSet, CWnd* pParent /*=NULL*/)
	: CDialog(CCommunicationDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommunicationDialog)
	m_CommunicationType = CommSet.CommType;
	m_Port = CommSet.SerialPort;
	m_Rate = CommSet.SerialRate;
	m_Connection = CommSet.EthernetConnection;
 	m_Address = CommSet.EthernetAddress;
	m_PCICardNumber = -1;
	//}}AFX_DATA_INIT
	Handle = CommSet.Handle;
	m_ConnectionString = CommSet.ConnectionString; 
}


void CCommunicationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommunicationDialog)
	DDX_Control(pDX, IDC_PCICOMBO, m_comboPCI);
	DDX_Radio(pDX, IDC_SERIALRADIO, m_CommunicationType);
	DDX_CBIndex(pDX, IDC_PORTCOMBO, m_Port);
	DDX_CBIndex(pDX, IDC_RATECOMBO, m_Rate);
	DDX_CBIndex(pDX, IDC_ETHERNETCOMBO, m_Connection);
	DDX_Text(pDX, IDC_ETHERNETEDIT, m_Address);
	DDX_CBIndex(pDX, IDC_PCICOMBO, m_PCICardNumber);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommunicationDialog, CDialog)
	//{{AFX_MSG_MAP(CCommunicationDialog)
	ON_BN_CLICKED(IDC_SERIALRADIO, OnSerialRadioButton)
	ON_BN_CLICKED(IDC_ETHERNETRADIO, OnEthernetRadioButton)
	ON_BN_CLICKED(IDC_PCIRADIO, OnPCIRadioButton)
	ON_BN_CLICKED(IDC_SIMULRADIO, OnSimulRadioButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDialog message handlers

void CCommunicationDialog::OnSerialRadioButton() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PORTCOMBO)->EnableWindow(TRUE);
	GetDlgItem(IDC_RATECOMBO)->EnableWindow(TRUE);
	GetDlgItem(IDC_ETHERNETEDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_PCICOMBO)->EnableWindow(FALSE);
}

void CCommunicationDialog::OnEthernetRadioButton() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PORTCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_RATECOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETEDIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_ETHERNETCOMBO)->EnableWindow(TRUE);
	GetDlgItem(IDC_PCICOMBO)->EnableWindow(FALSE);
}

void CCommunicationDialog::OnPCIRadioButton() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PORTCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_RATECOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETEDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_PCICOMBO)->EnableWindow(TRUE);
}

void CCommunicationDialog::OnSimulRadioButton() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PORTCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_RATECOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETEDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ETHERNETCOMBO)->EnableWindow(FALSE);
	GetDlgItem(IDC_PCICOMBO)->EnableWindow(FALSE);
}

BOOL CCommunicationDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	switch (m_CommunicationType)
	{
		case 0:
			OnSerialRadioButton();
			break;
		case 1:
			OnEthernetRadioButton();
			break;
		case 2:
			OnPCIRadioButton();
			break;
		case 3:
			OnSimulRadioButton();
			break;
	}

	// get all installed SPiiPlus PCI cards
	if (acsc_GetPCICards(PCICards, 16, &ObtainedCards))
	{
		if (ObtainedCards > 0)
		{
			CString str;
			for(int i = 0; i < ObtainedCards; i++)
			{
				str.Format("Bus: %d  Slot: %d", PCICards[i].BusNumber, PCICards[i].SlotNumber);
				m_comboPCI.AddString(str);
			}
			m_comboPCI.SetCurSel(0);
		}
		else
			GetDlgItem(IDC_PCIRADIO)->EnableWindow(FALSE);
	}
	else
		GetDlgItem(IDC_PCIRADIO)->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCommunicationDialog::OnOK() 
{
	// TODO: Add extra validation here
	// function opens corresponding communication channel
	UpdateData(TRUE);
	acsc_CloseHistoryBuffer(Handle);
	acsc_CloseComm(Handle);
	Handle = ACSC_INVALID;
	int Connection;
	switch(m_CommunicationType)
	{
		case 0:	//serial
			char str[256];
			((CComboBox *)GetDlgItem(IDC_RATECOMBO))->GetLBText(m_Rate, str);
			Handle = acsc_OpenCommSerial(m_Port + 1, atoi(str));
			m_ConnectionString.Format("Communication: Serial, COM%d, %s", m_Port + 1, str);
			break;
		case 1:	//ethernet
			Connection = (m_Connection == 0) ? ACSC_SOCKET_DGRAM_PORT : ACSC_SOCKET_STREAM_PORT;
			Handle = acsc_OpenCommEthernet((char *)LPCTSTR(m_Address), Connection);
			m_ConnectionString.Format("Communication: Ethernet, %s", (char *)LPCTSTR(m_Address));
			break;
		case 2:	//PCI bus
			Handle = acsc_OpenCommPCI(PCICards[m_PCICardNumber].SlotNumber);
			m_ConnectionString.Format("Communication: PCI bus, Bus %d, Slot %d", PCICards[m_PCICardNumber].BusNumber, PCICards[m_PCICardNumber].SlotNumber);
			break;
		case 3:	//simulator
			Handle = acsc_OpenCommDirect();
			m_ConnectionString.Format("Communication: Simulator");
			break;
	}
	if (Handle == ACSC_INVALID)
	{
		MessageBox("Communication link has not been established", "ACSC Terminal", MB_ICONWARNING);
		m_ConnectionString.Format("Communication: OFF");
	}
	else
		acsc_OpenHistoryBuffer(Handle, 100000);
	CDialog::OnOK();
}

void CCommunicationDialog::GetCommSettings(COMM_SETTINGS* CommSet)
{
	// retrieve communication settings
	CommSet->CommType = m_CommunicationType;
	CommSet->SerialPort = m_Port;
	CommSet->SerialRate = m_Rate;
	CommSet->EthernetConnection = m_Connection;
 	CommSet->EthernetAddress = m_Address;
	CommSet->Handle = Handle;
	CommSet->ConnectionString = m_ConnectionString; 
}