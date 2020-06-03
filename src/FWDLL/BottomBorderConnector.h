// BottomBorderConnector.h: interface for the BottomBorderConnector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOTTOMBORDERCONNECTOR_H__6FC3F5B2_E870_4AA4_804B_A43E185EE0AA__INCLUDED_)
#define AFX_BOTTOMBORDERCONNECTOR_H__6FC3F5B2_E870_4AA4_804B_A43E185EE0AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afxsock.h"
#include "Wcesock.h"
#include "Connector.h"
#include "Long.h"
#include "Connection.h"
#include "DetectDisconnectionThread.h"

// traffic type contstants
#define BBC_TT_BROADCAST			3
#define BBC_TT_UNICAST				12
#define BBC_TT_GROUPCAST			48
#define BBC_TT_TOP_BROADCAST		1
#define BBC_TT_TOP_UNICAST			4
#define BBC_TT_TOP_GROUPCAST		16
#define BBC_TT_BOTTOM_BROADCAST		2
#define BBC_TT_BOTTOM_UNICAST		8
#define BBC_TT_BOTTOM_GROUPCAST		32

// state constants
#define BBC_STATE_ACTIVE					1
#define BBC_STATE_WAIT_FOR_RECONNECTION		0
#define BBC_STATE_INACTIVE					-1

// time between pings
#define BBC_TIME_BETWEEN_PINGS				15000

class AFX_EXT_CLASS BottomBorderConnector : public Connector  
{
	DECLARE_SYNCHRONIZED()
private:
	CCeSocket *ss;
	int serverPortNum;	
	DetectDisconnectionThread	*dctDisconnect;
	bool flagPing;
	CObList	*connection;
	Connection	*currentConnection;

protected:
	bool keepWorking;

public:
	BottomBorderConnector();
	virtual ~BottomBorderConnector();

	BottomBorderConnector(CString name, int portNum);
	virtual void start();
	virtual void handle(Request* r);
	virtual void handle(Notification* n);
	POSITION hasActiveConnections();
	POSITION hasInactiveConnections();
	void stopWorking();
	void setFlagPing(bool value);
	bool getFlagPing();
};

#endif // !defined(AFX_BOTTOMBORDERCONNECTOR_H__6FC3F5B2_E870_4AA4_804B_A43E185EE0AA__INCLUDED_)
