// StaticDemo.h : main header file for the STATICDEMO application
//

#if !defined(AFX_STATICDEMO_H__3ACD5728_D7DB_4793_8DEC_3A2EC0FCC772__INCLUDED_)
#define AFX_STATICDEMO_H__3ACD5728_D7DB_4793_8DEC_3A2EC0FCC772__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticDemoApp:
// See StaticDemo.cpp for the implementation of this class
//

class CStaticDemoApp : public CWinApp
{
public:
	CStaticDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStaticDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICDEMO_H__3ACD5728_D7DB_4793_8DEC_3A2EC0FCC772__INCLUDED_)
