// BorderDemoDlg.h : header file
//

#if !defined(AFX_BORDERDEMODLG_H__E9A2AABD_7867_4DE7_B42E_0671923DC387__INCLUDED_)
#define AFX_BORDERDEMODLG_H__E9A2AABD_7867_4DE7_B42E_0671923DC387__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoDlg dialog
#include "..\FWDLL\FWDLL.h"

#include "CompA.h"
#include "..\StaticDemo\CompB.h"

#define BORDER_DEMO_PORT	9669
#define BORDER_DEMO_HOST	"ws02"

class CBorderDemoDlg : public CDialog
{
// Construction
public:
	CBorderDemoDlg(CWnd* pParent = NULL);	// standard constructor
	FIFODispatch *disp;
	Scaffold* s;
	RoundRobinScheduler* sch;
/*	HINSTANCE hDLL;
	Component* comp; */
	bool consumer;
	CompA* a;
	CompB* b;
	BottomBorderConnector* bbc;
	TopBorderConnector* tbc;
	ArchitectureAdapter* arch;

	void Done();
	void DisplayInvalidResult();

// Dialog Data
	//{{AFX_DATA(CBorderDemoDlg)
	enum { IDD = IDD_BORDERDEMO_DIALOG };
	int		m_first;
	int		m_second;
	int		m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorderDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBorderDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnMultiply();
	afx_msg void OnSubtract();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORDERDEMODLG_H__E9A2AABD_7867_4DE7_B42E_0671923DC387__INCLUDED_)
