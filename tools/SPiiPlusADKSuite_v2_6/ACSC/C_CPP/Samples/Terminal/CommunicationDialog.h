#if !defined(AFX_COMMUNICATIONDIALOG_H__C97F394F_4E72_4451_B542_297993FE2BB7__INCLUDED_)
#define AFX_COMMUNICATIONDIALOG_H__C97F394F_4E72_4451_B542_297993FE2BB7__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CommunicationDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCommunicationDialog dialog

class CCommunicationDialog : public CDialog
{
public:
	HANDLE Handle;
	CString m_ConnectionString;

protected:
	ACSC_PCI_SLOT PCICards[16];
	int ObtainedCards;

// Construction
public:
	CCommunicationDialog(COMM_SETTINGS& CommSet, CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CCommunicationDialog)
	enum { IDD = IDD_COMMDIALOG };
	CComboBox	m_comboPCI;
	int		m_CommunicationType;
	int		m_Port;
	int		m_Rate;
	int		m_Connection;
	CString	m_Address;
	int		m_PCICardNumber;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommunicationDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCommunicationDialog)
	afx_msg void OnSerialRadioButton();
	afx_msg void OnEthernetRadioButton();
	afx_msg void OnPCIRadioButton();
	afx_msg void OnSimulRadioButton();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void GetCommSettings(COMM_SETTINGS* CommSet);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMUNICATIONDIALOG_H__C97F394F_4E72_4451_B542_297993FE2BB7__INCLUDED_)
