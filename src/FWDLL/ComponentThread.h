// ComponentThread.h: interface for the ComponentThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
#define AFX_COMPONENTTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Component.h"
#include "BrickThread.h"

class AFX_EXT_CLASS ComponentThread : public Component
{
private:
	BrickThread* thrd;
public:
	ComponentThread();
	ComponentThread(CString name);
	virtual ~ComponentThread();
	virtual int Run();
};

#endif // !defined(AFX_COMPONENTTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
