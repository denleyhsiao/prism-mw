// TopBorderConnector.cpp: implementation of the TopBorderConnector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TopBorderConnector.h"
#include "Connection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TopBorderConnector::TopBorderConnector()
{
	isBlockedForSend = false;
}

TopBorderConnector::~TopBorderConnector()
{
	if(connection != NULL) delete connection;
}

TopBorderConnector::TopBorderConnector(CString name) : Connector(name)
{
	isBlockedForSend = false;
	connection = new CObList(5);
}

void TopBorderConnector::connect(CString hostName, int portNum)
{
	CTime now = CTime::GetCurrentTime();
	Connection *conn = new Connection(this, hostName, portNum,(long)now.GetTime());
	connection->AddTail(conn);
}

void TopBorderConnector::handle(Request *r) 
{
	ENTER_SYNCHRONIZED()
	ArchitectureEvent reqRecd(topId, ARCHEVENT_NAMES_REQRECD, 1);
	reqRecd.addEventDescriptor(0, r);
	fireEvent(&reqRecd);
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == TBC_STATE_ACTIVE) 
		{
			if (r->name == "Terminate")
			{
				conn->close();
			}
			else 
			{
				conn->writeRequest(r);
			} 
		}    
	}        
	ArchitectureEvent reqHdld(topId, ARCHEVENT_NAMES_REQHDLD, 1);
	reqHdld.addEventDescriptor(0, r);
	fireEvent(&reqHdld);
	LEAVE_SYNCHRONIZED()
}

void TopBorderConnector::synchronousSend(Request *r)
{
	ENTER_SYNCHRONIZED()
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == TBC_STATE_ACTIVE) 
		{
			if (r->name == "Terminate")
			{
				conn->close();
			}
			else 
			{
				conn->writeRequest(r);
				isBlockedForSend=true;
//				try
//				{
					while (isBlockedForSend)
					{
						Sleep(2000);
					}
//				}
//				catch (InterruptedException e){}
			} 
		}    
	}        
	ArchitectureEvent reqHdld(topId, ARCHEVENT_NAMES_REQHDLD, 1);
	reqHdld.addEventDescriptor(0, r);
	fireEvent(&reqHdld);
	LEAVE_SYNCHRONIZED()
}

void TopBorderConnector::syncHandle(Notification *notifyMsg) 
{
	isBlockedForSend=false;
	handle(notifyMsg);
}

void TopBorderConnector::handle(Notification *n)
{
	ENTER_SYNCHRONIZED()
	Connector::handle(n);
	ArchitectureEvent notifHdld(topId, ARCHEVENT_NAMES_NOTIFHDLD, 1);
	notifHdld.addEventDescriptor(0, n);
	fireEvent(&notifHdld);
	LEAVE_SYNCHRONIZED()
}

CObList* TopBorderConnector::getConnection()
{
	return connection;
}

POSITION TopBorderConnector::hasActiveConnections()
{
	POSITION ret = NULL;
	ENTER_SYNCHRONIZED()
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == TBC_STATE_ACTIVE)
		{
			ret = pos;
			break;
		}
	}
	LEAVE_SYNCHRONIZED()
	return ret;
}

double TopBorderConnector::getPercentConnected(POSITION connPos)
{
	double ret;
	ENTER_SYNCHRONIZED()
	Connection *conn = (Connection*)connection->GetAt(connPos);
	ret	= conn->getPercentConnected();
	LEAVE_SYNCHRONIZED()
	return ret;
}

double TopBorderConnector::getPercentDisconnected(POSITION connPos)
{
	double ret;
	ENTER_SYNCHRONIZED()
	Connection *conn = (Connection*)connection->GetAt(connPos);
	ret = conn->getPercentDisconnected();
	LEAVE_SYNCHRONIZED()
	return ret;
}

void TopBorderConnector::tearDownConnections()
{
	POSITION pos;
	for( pos = connection->GetHeadPosition(); pos != NULL; )
	{
		Connection* conn=(Connection *)connection->GetNext( pos );
		if (conn->getConnStatus() == TBC_STATE_ACTIVE) 
		{
			conn->teardown();		
		}    
	}        
}
