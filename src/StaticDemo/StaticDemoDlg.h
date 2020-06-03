// StaticDemoDlg.h : header file
//

#if !defined(AFX_STATICDEMODLG_H__A7BBC9A0_CD3D_4475_9B80_BE81C84CC9F5__INCLUDED_)
#define AFX_STATICDEMODLG_H__A7BBC9A0_CD3D_4475_9B80_BE81C84CC9F5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticDemoDlg dialog
#include "..\FWDLL\FWDLL.h"

#include "CompA.h"
#include "CompB.h"

class CStaticDemoDlg : public CDialog
{
// Construction
public:
	CStaticDemoDlg(CWnd* pParent = NULL);	// standard constructor
	FIFODispatch *disp;
	Scaffold* s;
	RoundRobinScheduler* sch;
/*	HINSTANCE hDLL;
	Component* comp; */
	CompA* a;
	CompB* b;
	Connector* c;
	ArchitectureAdapter* arch;

	void Done();
	void DisplayInvalidResult();

// Dialog Data
	//{{AFX_DATA(CStaticDemoDlg)
	enum { IDD = IDD_STATICDEMO_DIALOG };
	int		m_first;
	int		m_result;
	int		m_second;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	afx_msg void OnMul();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICDEMODLG_H__A7BBC9A0_CD3D_4475_9B80_BE81C84CC9F5__INCLUDED_)
