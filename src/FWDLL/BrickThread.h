#if !defined(AFX_BRICKTHREAD_H__9086A286_D04F_4FAA_B5CF_CF8218884F76__INCLUDED_)
#define AFX_BRICKTHREAD_H__9086A286_D04F_4FAA_B5CF_CF8218884F76__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// BrickThread.h : header file
//

#include "Brick.h"

class ComponentThread;
class ConnectorThread;
class PeerConnectorThread;

#define BRICKTHREAD_TYPE_COMPONENT	1
#define BRICKTHREAD_TYPE_CONNECTOR	2
#define BRICKTHREAD_TYPE_PEERCONN	4

/////////////////////////////////////////////////////////////////////////////
// BrickThread thread

class BrickThread : public CWinThread
{
	DECLARE_DYNCREATE(BrickThread)
private:
	int type;
	ComponentThread *comp;
	ConnectorThread *conr;
	PeerConnectorThread *pcon;

public:
	BrickThread(Brick *par,int type);
protected:
	BrickThread();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BrickThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~BrickThread();

	// Generated message map functions
	//{{AFX_MSG(BrickThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRICKTHREAD_H__9086A286_D04F_4FAA_B5CF_CF8218884F76__INCLUDED_)
