// BottomBorderConnector.cpp: implementation of the BottomBorderConnector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BottomBorderConnector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SYNCHRONIZED(BottomBorderConnector)

BottomBorderConnector::BottomBorderConnector()
{
	keepWorking = true;
	flagPing = true;
	connection = new CObList(5);	
}

BottomBorderConnector::~BottomBorderConnector()
{
	if(ss != NULL) delete ss;
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if(conn != NULL) delete conn;
	}        
	if(connection != NULL) delete connection;
}

BottomBorderConnector::BottomBorderConnector(CString name, int portNum) :  Connector(name)
{
	serverPortNum = portNum;	
	keepWorking = true;
	flagPing = true;
	connection = new CObList(5);	
}

void BottomBorderConnector::start()
{
//	try 
//	{
		ss = new CCeSocket(CCeSocket::FOR_LISTENING);
		ss->Create(serverPortNum);
		ss->Listen();
//	}
//	catch (Exception e) 
//	{
//	}
	CAsyncSocket sock;
	while (keepWorking) 
	{
//		try
//		{
			if(ss->Accept(sock) != 0) {
				currentConnection = new Connection(this, sock.m_hSocket);
			}
//		}
//		catch (Exception e) 
//		{
//		}
	}
}

void BottomBorderConnector::handle(Request* r)
{
	ENTER_SYNCHRONIZED()
	ArchitectureEvent reqRecd(topId, ARCHEVENT_NAMES_REQRECD, 1);
	reqRecd.addEventDescriptor(0,r);
	fireEvent(&reqRecd);

	if (r->name == "DeviceID")
	{
		Long* id = (Long*) r->getParameter("ID");
		if(id != NULL) {
			currentConnection->ID = id->getValue();
			connection->AddTail(currentConnection);
		}
	}
	else
	{
		Connector::handle(r);
	}

	ArchitectureEvent reqHdld(topId, ARCHEVENT_NAMES_REQHDLD, 1);
	reqHdld.addEventDescriptor(0,r);
	fireEvent(&reqHdld);
	LEAVE_SYNCHRONIZED()
}

void BottomBorderConnector::handle(Notification* n)
{
	ENTER_SYNCHRONIZED()
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == BBC_STATE_ACTIVE) 
		{
			conn->writeNotification(n);
		}    
	}        
	LEAVE_SYNCHRONIZED()
}

POSITION BottomBorderConnector::hasActiveConnections() 
{
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == BBC_STATE_ACTIVE)
		{
			return pos;
		}
	}        
	return NULL;
}

POSITION BottomBorderConnector::hasInactiveConnections() 
{
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == BBC_STATE_INACTIVE)
		{
			return pos;
		}
	}        
	return NULL;
}


void BottomBorderConnector::stopWorking() {
	keepWorking = false;
}

void BottomBorderConnector::setFlagPing(bool value)
{
	ENTER_SYNCHRONIZED()
	flagPing = value;
	LEAVE_SYNCHRONIZED()
}

bool BottomBorderConnector::getFlagPing() 
{
	return flagPing;
}


