// ReadConnectionThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ReadConnectionThread.h"
#include "TopBorderConnector.h"
#include "Connection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ReadConnectionThread

IMPLEMENT_DYNCREATE(ReadConnectionThread, CWinThread)

ReadConnectionThread::ReadConnectionThread()
{
}

ReadConnectionThread::~ReadConnectionThread()
{
}

BOOL ReadConnectionThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int ReadConnectionThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(ReadConnectionThread, CWinThread)
	//{{AFX_MSG_MAP(ReadConnectionThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ReadConnectionThread message handlers

int ReadConnectionThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
//	try
//	{
		while (keepWorking) 
		{
			CString line;
			(*reader) >> line;
			if(line == "<NotificationMessage>")
			{	
				(*reader) >> line;
				Notification notifyMsg(line);
				(*reader) >> line; // <Level>
				int level;
				(*reader) >> level;
				notifyMsg.level=level;
				int noOfParas;
				(*reader) >> noOfParas;
				CString nameOfPara;
				C2Object *valueOfPara;
				for(int i=0; i<noOfParas; i++)
				{
					(*reader) >> nameOfPara;
					(*reader) >> valueOfPara;
					notifyMsg.addParameter(nameOfPara, *valueOfPara);
				}
				conn->newNotificationArrived(&notifyMsg);
			}
		} //while ends
	// new
//	}
//	catch (Exception e) 
//	{
//		System.out.println("Caught Exception in RCT: while loop: " + e.toString());
//	}
//	return CWinThread::Run();
	return 0;
}

ReadConnectionThread::ReadConnectionThread(Connection *conn,  CArchive *rdr) : CWinThread()
{
	this->conn = conn;
	keepWorking = true;
//	try
//	{
		reader = rdr;
//	}
//	catch (IOException e) 
//	{
//	}
}

void ReadConnectionThread::stopWorking() 
{
	keepWorking = false;
}

