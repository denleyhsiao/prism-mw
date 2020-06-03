#if !defined(AFX_READCONNECTIONTHREAD_H__B0210D47_D77B_4832_B00F_1D2FCA0683BB__INCLUDED_)
#define AFX_READCONNECTIONTHREAD_H__B0210D47_D77B_4832_B00F_1D2FCA0683BB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ReadConnectionThread.h : header file
//

class Connection;

/////////////////////////////////////////////////////////////////////////////
// ReadConnectionThread thread

class ReadConnectionThread : public CWinThread
{
	DECLARE_DYNCREATE(ReadConnectionThread)
protected:
	ReadConnectionThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ReadConnectionThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~ReadConnectionThread();

	// Generated message map functions
	//{{AFX_MSG(ReadConnectionThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

protected:
	boolean keepWorking;
	Connection *conn;

public:
    CArchive *reader;
//    ObjectInputStream ir;
	ReadConnectionThread(Connection *conn,  CArchive *rdr);
    void stopWorking();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READCONNECTIONTHREAD_H__B0210D47_D77B_4832_B00F_1D2FCA0683BB__INCLUDED_)
