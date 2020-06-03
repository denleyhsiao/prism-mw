#if !defined(AFX_WORKERTHREAD_H__F0BA0A6E_790B_4011_B20D_CBF28735E499__INCLUDED_)
#define AFX_WORKERTHREAD_H__F0BA0A6E_790B_4011_B20D_CBF28735E499__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WorkerThread.h : header file
//

#include "Dispatch.h"
#include "Scheduler.h"
#include "Request.h"
#include "Notification.h"
#include "Peer.h"
#include "Architecture.h"


/////////////////////////////////////////////////////////////////////////////
// WorkerThread thread

class AFX_EXT_CLASS WorkerThread : public CWinThread
{
	DECLARE_DYNCREATE(WorkerThread)
private:
	Dispatch* messages;
	int timeStep;
	Scheduler* mySch;
	CString nameofThread;
	Message* m;

protected:
	WorkerThread();           // protected constructor used by dynamic creation

// Attributes
public:
	bool keepWorking;

// Operations
public:
	WorkerThread(Scheduler* sch,CString name, Dispatch* disp);
	WorkerThread(WorkerThread &adr);
	WorkerThread& operator=(WorkerThread& rhs);

	virtual int Run();
	void setTimeStep(int delay);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WorkerThread)
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~WorkerThread();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERTHREAD_H__F0BA0A6E_790B_4011_B20D_CBF28735E499__INCLUDED_)
