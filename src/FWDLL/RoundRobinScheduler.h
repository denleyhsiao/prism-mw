// RoundRobinScheduler.h: interface for the RoundRobinScheduler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDROBINSCHEDULER_H__378F3758_CD8C_4329_981C_C35AF889FDB7__INCLUDED_)
#define AFX_ROUNDROBINSCHEDULER_H__378F3758_CD8C_4329_981C_C35AF889FDB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scheduler.h"
#include "WorkerThread.h"

#define DEFAULT_COUNT	10

class AFX_EXT_CLASS RoundRobinScheduler : public Scheduler  
{
public:
	RoundRobinScheduler(int n);
	RoundRobinScheduler(Dispatch *disp);
	RoundRobinScheduler(Dispatch *disp, int n);
	virtual ~RoundRobinScheduler();
	RoundRobinScheduler(RoundRobinScheduler &adr);
	RoundRobinScheduler& operator=(RoundRobinScheduler& rhs);

private:
	int threadCount;
	WorkerThread** workerThreads;
	Dispatch *messages;

public:
	void setThreadCount(int n);
	int getThreadCount();
	virtual void start();
	virtual void stop();
	virtual void shutdown();
	void setTimeStep(int step);

};

#endif // !defined(AFX_ROUNDROBINSCHEDULER_H__378F3758_CD8C_4329_981C_C35AF889FDB7__INCLUDED_)
