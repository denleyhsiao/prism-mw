// RoundRobinScheduler.cpp: implementation of the RoundRobinScheduler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RoundRobinScheduler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RoundRobinScheduler::~RoundRobinScheduler()
{
/*
	for(int i=0; i < threadCount; i++ )
	{
		if(workerThreads[i] != NULL)
			delete workerThreads[i];
	}
*/
	if(workerThreads != NULL)
		delete [] workerThreads;
}

RoundRobinScheduler::RoundRobinScheduler(Dispatch* disp) {
	messages = disp;
	threadCount = DEFAULT_COUNT;
	workerThreads = new WorkerThread*[threadCount];
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i] = new WorkerThread(this, ""+i, messages);
	}
}

RoundRobinScheduler::RoundRobinScheduler(int n) {
	messages = NULL;
	threadCount = ( n < 1) ? DEFAULT_COUNT : n;
	workerThreads = new WorkerThread*[threadCount];
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i] = new WorkerThread(this, ""+i, messages);
	}
}

RoundRobinScheduler::RoundRobinScheduler(Dispatch* disp, int n) {
	messages = disp;
	threadCount = ( n < 1) ? DEFAULT_COUNT : n;
	workerThreads = new WorkerThread*[threadCount];
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i] = new WorkerThread(this, ""+i, messages);
		//workerThreads[i] = new WorkerThread(this,"Prism Worker "+ i, messages, i);
		//workerThreads[i].setTimeStep(3);
	}
}

RoundRobinScheduler::RoundRobinScheduler(RoundRobinScheduler &adr) {
	// deep copy not done as not used anywhere.
	messages = adr.messages;
	threadCount = adr.threadCount;
	workerThreads = adr.workerThreads;
}

RoundRobinScheduler& RoundRobinScheduler::operator=(RoundRobinScheduler& rhs) {
	// deep copy not done as not used anywhere.
	messages = rhs.messages;
	threadCount = rhs.threadCount;
	workerThreads = rhs.workerThreads;
	return *this;
}

void RoundRobinScheduler::setThreadCount(int n)
{
	if(n < 1 )
		return;
	if (n > threadCount) {
		WorkerThread** newWorkerThreads = new WorkerThread*[n];
		int i;
		for (i = 0; i < threadCount; i++)
			newWorkerThreads[i] = workerThreads[i];
		for (; i < n; i++)
		{
//          removed for Prism port to Palm
//				newWorkerThreads[i] = new WorkerThread(Thread.currentThread().getThreadGroup(),"Prism Worker "+ i, messages);
			newWorkerThreads[i] = new WorkerThread(this,"Prism Worker "+ i, messages);
		}
		delete [] workerThreads;
		workerThreads = newWorkerThreads;
		threadCount = n;
	}
	else if (n < threadCount) {
		for (int i = threadCount - 1; i >= n; i--)
			workerThreads[i]->keepWorking = false;
		threadCount = n;
		WorkerThread** newWorkerThreads = new WorkerThread*[threadCount];
		for (i = 0; i < threadCount; i++)
			newWorkerThreads[i] = workerThreads[i];
		delete [] workerThreads;
		workerThreads = newWorkerThreads;
	}
}

int RoundRobinScheduler::getThreadCount()
{
	return threadCount;
}

void RoundRobinScheduler::start() {
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i]->CreateThread(CREATE_SUSPENDED);
		workerThreads[i]->m_bAutoDelete = TRUE;
		workerThreads[i]->ResumeThread();
	}
}

void RoundRobinScheduler::stop()
{
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i]->keepWorking = false;
	}
	shutdown();
}

void RoundRobinScheduler::shutdown()
{
//	try
//	{
		Sleep(2000);
//	}catch(...){}
	exit(0);
}

void RoundRobinScheduler::setTimeStep(int step)
{
	for(int i=0; i < threadCount; i++ )
	{
		workerThreads[i]->setTimeStep(step);
	}
}
