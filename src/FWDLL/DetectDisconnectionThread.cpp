// DetectDisconnectionThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "DetectDisconnectionThread.h"
#include "BottomBorderConnector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DetectDisconnectionThread

IMPLEMENT_DYNCREATE(DetectDisconnectionThread, CWinThread)

DetectDisconnectionThread::DetectDisconnectionThread()
{
}

DetectDisconnectionThread::~DetectDisconnectionThread()
{
}

DetectDisconnectionThread::DetectDisconnectionThread(Connector *parent, long timeBetweenPings) : CWinThread()
{
	parentConnector = (BottomBorderConnector*) parent;
	keepWorking = true;
	this->timeBetweenPings = timeBetweenPings;
	freqOfDisconnection = 0;
}

BOOL DetectDisconnectionThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int DetectDisconnectionThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(DetectDisconnectionThread, CWinThread)
	//{{AFX_MSG_MAP(DetectDisconnectionThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DetectDisconnectionThread message handlers

int DetectDisconnectionThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
//	try
//	{
		int pingID = 0;
		while(keepWorking)
		{
			if (parentConnector->getFlagPing() && (parentConnector->hasActiveConnections() != NULL))
			{
				pingID++;
				Notification n("BBC_CheckConnection");
				n.addParameter("PingID", Long(pingID));
				parentConnector->handle(&n);
			}
			parentConnector->setFlagPing(true);
			//wake up periodically to check the connection
			Sleep(timeBetweenPings); //
		}
//	}
//	catch(Exception e)
//	{
//	System.out.println("BBC_DDT: Exception in run() -> " + e.toString());
//	}
	
	//return CWinThread::Run();
	return 0;
}

int DetectDisconnectionThread::getFreqOfDisconnection()
{
	return freqOfDisconnection;
}

void DetectDisconnectionThread::logDisconnectionFrequency()
{
	freqOfDisconnection++;
}
