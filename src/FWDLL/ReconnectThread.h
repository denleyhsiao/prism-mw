#if !defined(AFX_RECONNECTTHREAD_H__8032878B_03E6_4C3B_A735_5A4C8684BE66__INCLUDED_)
#define AFX_RECONNECTTHREAD_H__8032878B_03E6_4C3B_A735_5A4C8684BE66__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ReconnectThread.h : header file
//

class Connection;

/////////////////////////////////////////////////////////////////////////////
// ReconnectThread thread

class ReconnectThread : public CWinThread
{
	DECLARE_DYNCREATE(ReconnectThread)
protected:
	ReconnectThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ReconnectThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~ReconnectThread();

	// Generated message map functions
	//{{AFX_MSG(ReconnectThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	Connection *conn;

public:
    long timeBetweenRetry;
    int maxNumOfTry;
	ReconnectThread(Connection *conn, long sleepTime, int numOfTry);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECONNECTTHREAD_H__8032878B_03E6_4C3B_A735_5A4C8684BE66__INCLUDED_)
