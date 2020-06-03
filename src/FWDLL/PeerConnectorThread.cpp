// PeerConnectorThread.cpp: implementation of the PeerConnectorThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeerConnectorThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PeerConnectorThread::PeerConnectorThread()
{
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_PEERCONN);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

PeerConnectorThread::~PeerConnectorThread()
{
	if(thrd != NULL) delete thrd;
}

PeerConnectorThread::PeerConnectorThread(CString name) : PeerConnector(name) {
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_PEERCONN);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

int PeerConnectorThread::Run() {
	return 0;
}