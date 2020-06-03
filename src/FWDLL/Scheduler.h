// Scheduler.h: interface for the Scheduler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCHEDULER_H__48987EB8_37FB_4119_9A39_A1673692AE90__INCLUDED_)
#define AFX_SCHEDULER_H__48987EB8_37FB_4119_9A39_A1673692AE90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS Scheduler  
{
public:
	Scheduler();
	virtual ~Scheduler();
	Scheduler(Scheduler &adr);
	Scheduler& operator=(Scheduler& rhs);

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void shutdown() = 0;
};

#endif // !defined(AFX_SCHEDULER_H__48987EB8_37FB_4119_9A39_A1673692AE90__INCLUDED_)
