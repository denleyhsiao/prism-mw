// BrickThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "BrickThread.h"
#include "ComponentThread.h"
#include "ConnectorThread.h"
#include "PeerConnectorThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BrickThread

IMPLEMENT_DYNCREATE(BrickThread, CWinThread)

BrickThread::BrickThread() : CWinThread()
{
	this->type = 0;
}

BrickThread::BrickThread(Brick *par, int itype) : CWinThread()
{
	this->type = 0;
	if(itype == BRICKTHREAD_TYPE_COMPONENT) {
		this->type = BRICKTHREAD_TYPE_COMPONENT;
		comp = (ComponentThread *)par;
	}
	if(itype == BRICKTHREAD_TYPE_CONNECTOR) {
		this->type = BRICKTHREAD_TYPE_CONNECTOR;
		conr = (ConnectorThread *)par;
	}
	if(itype == BRICKTHREAD_TYPE_PEERCONN) {
		this->type = BRICKTHREAD_TYPE_PEERCONN;
		pcon = (PeerConnectorThread *)par;
	}
}

BrickThread::~BrickThread()
{
}

BOOL BrickThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int BrickThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(BrickThread, CWinThread)
	//{{AFX_MSG_MAP(BrickThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BrickThread message handlers

int BrickThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(type == BRICKTHREAD_TYPE_COMPONENT) {
		return comp->Run();
	}
	if(type == BRICKTHREAD_TYPE_CONNECTOR) {
		return conr->Run();
	}
	if(type == BRICKTHREAD_TYPE_PEERCONN) {
		return pcon->Run();
	}
	return 0;
}
