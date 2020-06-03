// MonitorConnectionThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "MonitorConnectionThread.h"
#include "TopBorderConnector.h"
#include "Connection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MonitorConnectionThread

IMPLEMENT_DYNCREATE(MonitorConnectionThread, CWinThread)

MonitorConnectionThread::MonitorConnectionThread()
{
}

MonitorConnectionThread::~MonitorConnectionThread()
{
}

BOOL MonitorConnectionThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int MonitorConnectionThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(MonitorConnectionThread, CWinThread)
	//{{AFX_MSG_MAP(MonitorConnectionThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MonitorConnectionThread message handlers

MonitorConnectionThread::MonitorConnectionThread(Connection *parent, long timeBetweenPings) : CWinThread()
{
	parentConnection =  parent;
	keepWorking = true;
	this->timeBetweenPings = timeBetweenPings;
	startTime = (long) CTime::GetCurrentTime().GetTime();
}
    
void MonitorConnectionThread::stopWorking () 
{
	keepWorking = false;
}

int MonitorConnectionThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
//	try
//	{
		int pingID = 0;
		while(keepWorking)
		{
			long now = (long) CTime::GetCurrentTime().GetTime();
			if ((parentConnection->timeLastActive - now) > TBC_TIME_BETWEEN_PINGS)
			{
				pingID++;
				Request r("CheckConnection");
				r.addParameter("PingID",Long(pingID));
				parentConnection->writeRequest(&r);
			}
			if((pingID % 2 == 0) && (pingID > 0) )
			{
				parentConnection->teardown();
			}
			//wake up periodically to check the connection
			Sleep(timeBetweenPings); //
		}
//	}
//	catch(Exception e)
//	{
//		System.out.println("TBC_DDT: Exception in run() -> " + e.toString());
//	}
	
//	return CWinThread::Run();
	return 0;
}
