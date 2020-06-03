#if !defined(AFX_DETECTDISCONNECTIONTHREAD_H__E1224CC1_E89C_4D22_BA94_212A51C01E71__INCLUDED_)
#define AFX_DETECTDISCONNECTIONTHREAD_H__E1224CC1_E89C_4D22_BA94_212A51C01E71__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DetectDisconnectionThread.h : header file
//

#include "Connector.h"
class BottomBorderConnector;

/////////////////////////////////////////////////////////////////////////////
// DetectDisconnectionThread thread

class DetectDisconnectionThread : public CWinThread
{
	DECLARE_DYNCREATE(DetectDisconnectionThread)
protected:
	DetectDisconnectionThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DetectDisconnectionThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~DetectDisconnectionThread();

	// Generated message map functions
	//{{AFX_MSG(DetectDisconnectionThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	boolean keepWorking;
	BottomBorderConnector *parentConnector;
	long timeBetweenPings;
	int freqOfDisconnection; 
public:
	DetectDisconnectionThread(Connector *parent, long timeBetweenPings);
	int getFreqOfDisconnection();
	void logDisconnectionFrequency();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETECTDISCONNECTIONTHREAD_H__E1224CC1_E89C_4D22_BA94_212A51C01E71__INCLUDED_)
