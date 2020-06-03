// ReconnectThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ReconnectThread.h"
#include "TopBorderConnector.h"
#include "Connection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ReconnectThread

IMPLEMENT_DYNCREATE(ReconnectThread, CWinThread)

ReconnectThread::ReconnectThread()
{
}

ReconnectThread::~ReconnectThread()
{
}

BOOL ReconnectThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int ReconnectThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(ReconnectThread, CWinThread)
	//{{AFX_MSG_MAP(ReconnectThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ReconnectThread message handlers

int ReconnectThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	bool reconnected = false;
	int numOfTry = 0;
	CCeSocket streamConn;
	streamConn.Create();
	while ( !reconnected && numOfTry < maxNumOfTry ) 
	{
//		try 
//		{
			numOfTry++;
			if(streamConn.Connect((LPCTSTR)conn->host,conn->port) != 0) {
				reconnected = true;
				Request r("DeviceID");
				r.addParameter("ID",Long(conn->ID));
				conn->writeRequest(&r);
				break;
			} else {
//		}
//		catch (Exception e) 
//		{
//			System.out.println("Reconnection Attempt " + numOfTry + ": " + e.toString());
//			try 
//			{
				Sleep(timeBetweenRetry);             // sleep for some time before try again
//			}
//			catch (Exception ex)
//			{
//			}
			}
//		}
	}

	if (reconnected) 
	{
		// successfully reconnected
		conn->reset(streamConn);	
	} 
	else 
	{
//		System.out.println("Reconnect to " + conn.host + ":" + conn.port + " failed");
	}
//	return CWinThread::Run();
	return 0;
}

ReconnectThread::ReconnectThread(Connection *conn, long sleepTime, int numOfTry)
{	
	this->conn = conn;
	timeBetweenRetry = sleepTime;
	maxNumOfTry = numOfTry;
}
