// BorderDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BorderDemo.h"
#include "BorderDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoApp

BEGIN_MESSAGE_MAP(CBorderDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CBorderDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoApp construction

CBorderDemoApp::CBorderDemoApp()
	: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBorderDemoApp object

CBorderDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBorderDemoApp initialization

BOOL CBorderDemoApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CBorderDemoDlg dlg;
	m_pMainWnd = &dlg;

	// check which site is it 
	if(AfxMessageBox(_T("Is this a message consumer"),MB_YESNO | MB_ICONQUESTION) == IDYES)
		dlg.consumer = true;
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
