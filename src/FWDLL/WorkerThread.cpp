// WorkerThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "WorkerThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WorkerThread

IMPLEMENT_DYNCREATE(WorkerThread, CWinThread)

WorkerThread::WorkerThread() {
	this->timeStep = 0;
}

WorkerThread::WorkerThread(Scheduler* sch,CString name, Dispatch* disp) : CWinThread() {
	this->timeStep = 0;
	this->messages = disp;
	this->keepWorking = true;
	this->mySch = sch;
	this->nameofThread = name;
}

WorkerThread::~WorkerThread() {
}

WorkerThread::WorkerThread(WorkerThread &adr) {
	this->timeStep = adr.timeStep;
	this->messages = adr.messages;
	this->keepWorking = adr.keepWorking;
	this->mySch = adr.mySch;
	this->nameofThread = adr.nameofThread;
}

WorkerThread& WorkerThread::operator=(WorkerThread& rhs) {
	this->timeStep = rhs.timeStep;
	this->messages = rhs.messages;
	this->keepWorking = rhs.keepWorking;
	this->mySch = rhs.mySch;
	this->nameofThread = rhs.nameofThread;
	return *this;
}

BOOL WorkerThread::InitInstance() {
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int WorkerThread::ExitInstance() {
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

int WorkerThread::Run() {
	int count = 0;
	while(keepWorking)
	{
//		try 
//		{
			m = messages->getMessage();
			if(m != NULL) {
				++count;
				CObject* via = m->via;
				if(m->IsKindOf(RUNTIME_CLASS(Request)) && via != NULL) {
					if(via->IsKindOf(RUNTIME_CLASS(Architecture)))
					{
						((Architecture*) via)->handle((Request&)*m);
					} else if(via->IsKindOf(RUNTIME_CLASS(Connector))) {
						((Connector*) via)->handle((Request*)m);
					} // Component case not handled
				}
				else 
				if(m->IsKindOf(RUNTIME_CLASS(Notification)) && via != NULL) {
					if(via->IsKindOf(RUNTIME_CLASS(Architecture)))
					{
						((Architecture*) via)->handle((Notification&)*m);
					} else if(via->IsKindOf(RUNTIME_CLASS(Connector))) {
						((Connector*) via)->handle((Notification*)m);
					} // Component case not handled
				}
				else
				if(m->IsKindOf(RUNTIME_CLASS(Peer)) && via != NULL) {
					if(via->IsKindOf(RUNTIME_CLASS(Architecture)))
					{
						((Architecture*) via)->handle((Peer&)*m);
					} else if(via->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
						((PeerConnector*) via)->handle((Peer*)m);
					} // Component case not handled
				}
				if(m->name == "Terminate")
				{
					mySch->stop();
					return 0;
				}
				m->destructParameters();
				delete m;
				m = NULL;
				/*if(count % 100 == 1)
				{
					System.out.println("WorkerThread: gc invoked at " + count);
					System.gc();
				}*/					
			}
			else
			{
			}
//		} 
//		catch (...) // Catch exceptions while dispatching the message
//		{
//		}
//		yield();
		
		if (timeStep > 0)
		{
//			try
//			{
				Sleep(timeStep);
//			}
//			catch (...) // Timer Interrupt
//			{
//			}
		}
	}
	return 0;
}

void WorkerThread::setTimeStep(int delay) {
	this->timeStep = delay;
}
