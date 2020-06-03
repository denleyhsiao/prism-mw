#if !defined(AFX_ACCEPTCONNECTIONTHREAD_H__BC87E5A2_DC40_4C44_9983_521A793A747C__INCLUDED_)
#define AFX_ACCEPTCONNECTIONTHREAD_H__BC87E5A2_DC40_4C44_9983_521A793A747C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AcceptConnectionThread.h : header file
//

#include "Afxsock.h"
#include "Connector.h"

class BottomBorderConnector;
class Connection;

/////////////////////////////////////////////////////////////////////////////
// AcceptConnectionThread thread

class AcceptConnectionThread : public CWinThread
{
	DECLARE_DYNCREATE(AcceptConnectionThread)
protected:
	AcceptConnectionThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AcceptConnectionThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~AcceptConnectionThread();

	// Generated message map functions
	//{{AFX_MSG(AcceptConnectionThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
	boolean keepWorking;
    BottomBorderConnector *parentConnector;
    CArchive *reader;
	Connection *connection;

public:
    AcceptConnectionThread(Connection *conn, Connector *parent, CArchive *reader);
    void stopWorking();
private:
	CString readLine();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCEPTCONNECTIONTHREAD_H__BC87E5A2_DC40_4C44_9983_521A793A747C__INCLUDED_)
