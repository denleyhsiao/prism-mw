// ConnectorThread.h: interface for the ConnectorThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
#define AFX_CONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Connector.h"
#include "BrickThread.h"

class AFX_EXT_CLASS ConnectorThread : public Connector
{
private:
	BrickThread* thrd;
public:
	ConnectorThread();
	ConnectorThread(CString name);
	virtual ~ConnectorThread();
	virtual int Run();
};

#endif // !defined(AFX_CONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
