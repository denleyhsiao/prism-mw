// Scaffold.h: interface for the Scaffold class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCAFFOLD_H__D92AF028_F4A9_4EF6_A4E3_4482C94F7937__INCLUDED_)
#define AFX_SCAFFOLD_H__D92AF028_F4A9_4EF6_A4E3_4482C94F7937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Dispatch.h"
#include "Scheduler.h"
#include "Monitor.h"

#define SCAFFOLD_TYPE_SCHEDULER		1
#define SCAFFOLD_TYPE_MONITOR		2
#define SCAFFOLD_TYPE_DISPATCH		4

class AFX_EXT_CLASS Scaffold  
{
protected:
	int type;
    Dispatch* messageDispatch;
    Scheduler* scheduler;
    Monitor* monitor;

public:
	Scaffold();
	virtual ~Scaffold();
    Scaffold(int type);
	Scaffold(Scaffold &adr);
	Scaffold& operator=(Scaffold& rhs);

    int getType();
    void setDispatch(Dispatch* dispatch);
    void setScheduler(Scheduler* sch);
    void setMonitor(Monitor* mon);
    void call(CString command, CObject* param);
    void call(CString command, CObject* param, boolean syncCall);

};

#endif // !defined(AFX_SCAFFOLD_H__D92AF028_F4A9_4EF6_A4E3_4482C94F7937__INCLUDED_)
