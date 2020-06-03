#if !defined(AFX_MONITORCONNECTIONTHREAD_H__D96E9B37_88E6_4397_8527_2EC5EC3CDE5B__INCLUDED_)
#define AFX_MONITORCONNECTIONTHREAD_H__D96E9B37_88E6_4397_8527_2EC5EC3CDE5B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MonitorConnectionThread.h : header file
//


class Connection;

/////////////////////////////////////////////////////////////////////////////
// MonitorConnectionThread thread

class MonitorConnectionThread : public CWinThread
{
	DECLARE_DYNCREATE(MonitorConnectionThread)
protected:
	MonitorConnectionThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MonitorConnectionThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~MonitorConnectionThread();

	// Generated message map functions
	//{{AFX_MSG(MonitorConnectionThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	boolean keepWorking;
    Connection *parentConnection;
    long timeBetweenPings;
	long startTime;
	long totalTimeElapsed;
	long totalTimeConnected;
	long totalTimeDisconnected;

public:
    MonitorConnectionThread(Connection *parent, long timeBetweenPings);
    void stopWorking();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORCONNECTIONTHREAD_H__D96E9B37_88E6_4397_8527_2EC5EC3CDE5B__INCLUDED_)
