// ConnectorThread.cpp: implementation of the ConnectorThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ConnectorThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConnectorThread::ConnectorThread()
{
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_CONNECTOR);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

ConnectorThread::~ConnectorThread()
{
	if(thrd != NULL) delete thrd;
}

ConnectorThread::ConnectorThread(CString name) : Connector(name) {
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_CONNECTOR);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

int ConnectorThread::Run() {
	return 0;
}