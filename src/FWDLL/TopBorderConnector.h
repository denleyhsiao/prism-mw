// TopBorderConnector.h: interface for the TopBorderConnector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOPBORDERCONNECTOR_H__7E148C9A_570D_482D_8959_C8E7CDB4CB49__INCLUDED_)
#define AFX_TOPBORDERCONNECTOR_H__7E148C9A_570D_482D_8959_C8E7CDB4CB49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Connector.h"

#define TBC_TT_BROADCAST			3
#define TBC_TT_UNICAST				12
#define TBC_TT_GROUPCAST			48
#define TBC_TT_TOP_BROADCAST		1
#define TBC_TT_TOP_UNICAST			4
#define TBC_TT_TOP_GROUPCAST		16
#define TBC_TT_BOTTOM_BROADCAST		2
#define TBC_TT_BOTTOM_UNICAST		8
#define TBC_TT_BOTTOM_GROUPCAST		32

#define TBC_STATE_ACTIVE					1
#define TBC_STATE_WAIT_FOR_RECONNECTION		0
#define TBC_STATE_INACTIVE					-1

    // time between pings
#define TBC_TIME_BETWEEN_PINGS		5000
#define TBC_TIME_BETWEEN_RETRY		15000
#define TBC_MAX_TRY					10


class AFX_EXT_CLASS TopBorderConnector : public Connector  
{
	DECLARE_SYNCHRONIZED()
public:
	TopBorderConnector();
	virtual ~TopBorderConnector();

private:
	CObList *connection;
public:
	bool isBlockedForSend;

public:
	TopBorderConnector(CString name);
	void connect(CString hostName, int portNum);
	void handle(Request *r);
    void synchronousSend(Request *r);
	void syncHandle(Notification *notifyMsg);
	void handle(Notification *n);
	CObList* getConnection();
	POSITION hasActiveConnections();
	double getPercentConnected(POSITION connPos);
	double getPercentDisconnected(POSITION connPos);
	void tearDownConnections();
};

#endif // !defined(AFX_TOPBORDERCONNECTOR_H__7E148C9A_570D_482D_8959_C8E7CDB4CB49__INCLUDED_)
