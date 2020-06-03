// ComponentThread.cpp: implementation of the ComponentThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComponentThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentThread::ComponentThread()
{
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_COMPONENT);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

ComponentThread::~ComponentThread()
{
	if(thrd != NULL) delete thrd;
}

ComponentThread::ComponentThread(CString name) : Component(name) {
	thrd = new BrickThread(this,BRICKTHREAD_TYPE_COMPONENT);
	thrd->CreateThread(CREATE_SUSPENDED);
	thrd->m_bAutoDelete = TRUE;
	thrd->ResumeThread();
}

int ComponentThread::Run() {
	return 0;
}