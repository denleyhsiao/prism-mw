// BorderDemo.h : main header file for the BORDERDEMO application
//

#if !defined(AFX_BORDERDEMO_H__2B69F853_99A3_4D0C_B54C_08E2B23B7C8A__INCLUDED_)
#define AFX_BORDERDEMO_H__2B69F853_99A3_4D0C_B54C_08E2B23B7C8A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoApp:
// See BorderDemo.cpp for the implementation of this class
//

class CBorderDemoApp : public CWinApp
{
public:
	CBorderDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorderDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBorderDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORDERDEMO_H__2B69F853_99A3_4D0C_B54C_08E2B23B7C8A__INCLUDED_)
