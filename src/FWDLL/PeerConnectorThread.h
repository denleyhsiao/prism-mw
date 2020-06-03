// PeerConnectorThread.h: interface for the PeerConnectorThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEERCONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
#define AFX_PEERCONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PeerConnector.h"
#include "BrickThread.h"

class AFX_EXT_CLASS PeerConnectorThread : public PeerConnector
{
private:
	BrickThread* thrd;
public:
	PeerConnectorThread();
	PeerConnectorThread(CString name);
	virtual ~PeerConnectorThread();
	virtual int Run();
};

#endif // !defined(AFX_PEERCONNECTORTHREAD_H__E5533178_CEED_4520_9090_806583FA3385__INCLUDED_)
