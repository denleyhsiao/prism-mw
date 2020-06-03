// Connection.h: interface for the Connection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTION_H__71BEA4F2_76A3_42AA_8CC5_E0AB414D6AE2__INCLUDED_)
#define AFX_CONNECTION_H__71BEA4F2_76A3_42AA_8CC5_E0AB414D6AE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afxsock.h"
#include "Connector.h"
#include "Long.h"
#include "AcceptConnectionThread.h"

class ReadConnectionThread;
class MonitorConnectionThread;
class BottomBorderConnector;
class TopBorderConnector;

class Connection  : public CObject
{
private:
	BottomBorderConnector *parentConnector;
	CCeSocket socket;
	CSocketFile	*socketFile;
	CArchive	*reader;
	CArchive	*writer;
    //OutputStream os;
	//ObjectOutputStream  writer;
    int connStatus;             // indicator of status of the connection 
    AcceptConnectionThread *act;
	long startInactive;
	long startActive;
	long startConnection;

public:
	long timeLastActive;
	long timeConnected;
	long timeDisconnected;
	long ID;

public:
	Connection();
	virtual ~Connection();
	Connection(Connector *parent, SOCKET sock);
	int getConnStatus();
	void close();
    void writeNotification(Notification *n);

public:
	CString host;
	int port;
private:
	TopBorderConnector *topConnector;
	ReadConnectionThread *readConn;
	MonitorConnectionThread *discThread;

public:
    Connection(Connector *parent, CString hostName, int portNum, long identifier);
	double getPercentConnected();
	double getPercentDisconnected();
	void reconnect();
	void reset(SOCKET sc);
	void writeRequest(Request *r);
	void teardown();
	void newNotificationArrived(Notification *n);
};

#endif // !defined(AFX_CONNECTION_H__71BEA4F2_76A3_42AA_8CC5_E0AB414D6AE2__INCLUDED_)
