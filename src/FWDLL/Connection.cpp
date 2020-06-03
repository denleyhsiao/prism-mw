// Connection.cpp: implementation of the Connection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Connection.h"
#include "BottomBorderConnector.h"
#include "TopBorderConnector.h"
#include "ReadConnectionThread.h"
#include "MonitorConnectionThread.h"
#include "ReconnectThread.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Connection::Connection()
{
	parentConnector = NULL;
	topConnector = NULL;
	act = NULL;
	socketFile = NULL;
	reader = NULL;
	writer = NULL;
	readConn = NULL;
	discThread = NULL;
}

Connection::~Connection()
{
	if(act != NULL) delete act;
	if(socketFile != NULL) delete socketFile;
	if(reader != NULL) delete reader;
	if(writer != NULL) delete writer;
//	if(readConn != NULL) delete readConn;
//	if(discThread != NULL) delete discThread;
}
  
Connection::Connection(Connector *parent, SOCKET sock) 
{
	parentConnector = NULL;
	topConnector = NULL;
	socketFile = NULL;
	reader = NULL;
	writer = NULL;
	readConn = NULL;
	discThread = NULL;
	parentConnector = (BottomBorderConnector*)parent;
	socket.Create();
	socket.Attach(sock);
	socketFile = new CSocketFile(&socket);
	reader = new CArchive(socketFile,CArchive::load);
	writer = new CArchive(socketFile,CArchive::store);
	connStatus = BBC_STATE_ACTIVE;
//	startActive=System.currentTimeMillis();
//	startConnection=System.currentTimeMillis();
//	timeConnected=0;
//	timeDisconnected=0;
	act = new AcceptConnectionThread(this, parent, reader); 
	act->CreateThread(CREATE_SUSPENDED);
	act->m_bAutoDelete = TRUE;
	act->ResumeThread();
}

int Connection::getConnStatus()
{
	return connStatus;
}

void Connection::close()
{
	reader->Close();
	writer->Close();
	socketFile->Close();

	if(parentConnector != NULL) {
	//	try 
	//	{
			connStatus = BBC_STATE_INACTIVE;	
			socket.Close();
			act->stopWorking();			
	//	}
	//	catch (Exception e) 
	//	{
	//	}
	} else if(topConnector != NULL) {
		connStatus = TBC_STATE_INACTIVE;
	//	try 
	//	{
			long now = (long) CTime::GetCurrentTime().GetTime();
			timeConnected += now - startActive;
			startInactive = now;
			socket.Close();
			readConn->stopWorking();
	//	}
	//	catch (Exception e)
	//	{
	//		System.out.println("TBC Connection: Caught exception in close() " + e.toString());
	//	}
	}
}

void Connection::writeNotification(Notification* n)
{
//	try
//	{
		CString str = "<NotificationMessage>";
		(*writer) << str;
		(*writer) << n->name;
		(*writer) << "<Level>\n";
		(*writer) << n->level;
		// send across the number of the parameters in the Message
		int numberOfParameters = n->parameters.GetCount();
		(*writer) << numberOfParameters;
		CString nameOfParameter;
		C2Object* valueOfParameter;
		POSITION pos;
		for(pos = n->parameters.GetStartPosition(); pos != NULL ; )
		{
			n->parameters.GetNextAssoc( pos, nameOfParameter, (CObject*&)valueOfParameter );
			(*writer) << nameOfParameter;
			(*writer) << valueOfParameter;
		}
//	}        // matches try
//	catch(IOException ioe)
//	{
//		System.out.println("Caught IO-Exception in  handle (n) : " + ioe.toString());
//		this.close();
//	}

//	catch(Exception e)
//	{
//		System.out.println("Caught Exception in  handle (n) : " + e.toString());
//	}
}

Connection::Connection(Connector *parent, CString hostName, int portNum, long identifier)
{
	parentConnector = NULL;
	topConnector = NULL;
	socketFile = NULL;
	reader = NULL;
	writer = NULL;
	act = NULL;
	readConn = NULL;
	discThread = NULL;

	topConnector = (TopBorderConnector *)parent;
	host = hostName;
	port = portNum;
	ID=identifier;
//	try 
//	{
//		System.out.println("TBC connecting to " + hostName + ":" + portNum);
		socket.Create();
		socket.Connect((LPCTSTR)host,port);
		
		startActive = CTime::GetCurrentTime().GetTime();
		startConnection = startActive;
		timeConnected=0;
		timeDisconnected=0;
		socketFile = new CSocketFile(&socket);
		reader = new CArchive(socketFile,CArchive::load);
		writer = new CArchive(socketFile,CArchive::store);
		connStatus = TBC_STATE_ACTIVE;

		readConn = new ReadConnectionThread(this, reader);
		readConn->CreateThread(CREATE_SUSPENDED);
		readConn->m_bAutoDelete = TRUE;
		readConn->ResumeThread();
		discThread = new MonitorConnectionThread(this, TBC_TIME_BETWEEN_PINGS);
		discThread->CreateThread(CREATE_SUSPENDED);
		discThread->m_bAutoDelete = TRUE;
		discThread->ResumeThread();
		Request r("DeviceID");
		r.addParameter("ID",Long(ID));
		writeRequest(&r);
//	}
//	catch (IOException e) 
//	{
//		System.out.println("\nException in Connection: constructor ->" + e.toString());
//	}
}

double Connection::getPercentConnected()
{
	long t = (long) CTime::GetCurrentTime().GetTime();
	long tc;
	if (connStatus == TBC_STATE_ACTIVE)
	{
		 tc = timeConnected + t - startActive;
	}
	else
	{
		tc = timeConnected;
	}
	return(((double)100 * tc) / t);
}

double Connection::getPercentDisconnected()
{
	long now = (long) CTime::GetCurrentTime().GetTime();
	long t= now - startConnection;
	long tc;
	if (connStatus == TBC_STATE_ACTIVE)
	{
		tc = timeDisconnected + now - startInactive;
	}
	else
	{
		tc = timeDisconnected;
	}
	return(((double)100 * tc) / t);
}

void Connection::reconnect()
{
	// fork a ReconnectThread to attempt reconnection		
	ReconnectThread *reconnThread = new ReconnectThread(this, TBC_TIME_BETWEEN_RETRY, TBC_MAX_TRY);
	reconnThread->CreateThread(CREATE_SUSPENDED);
	reconnThread->m_bAutoDelete = TRUE;
	reconnThread->ResumeThread();
}

void Connection::reset(SOCKET sc) 
{
	socket.Attach(sc);
	long now = (long) CTime::GetCurrentTime().GetTime();
	startActive = now;
	timeDisconnected += now - startInactive;
	if(socketFile != NULL) delete socketFile;
	if(reader != NULL) delete reader;
	if(writer != NULL) delete writer;
//	if(readConn != NULL) delete readConn;
	socketFile = new CSocketFile(&socket);
	reader = new CArchive(socketFile,CArchive::load);
	writer = new CArchive(socketFile,CArchive::store);
	readConn = new ReadConnectionThread(this, reader);
	readConn->CreateThread(CREATE_SUSPENDED);
	readConn->m_bAutoDelete = TRUE;
	readConn->ResumeThread();
	connStatus = TBC_STATE_ACTIVE;        // make a note that the connection is back 
}

void Connection::writeRequest(Request *r)
{
//	try
//	{
		// an identifier for both ends to recognize a Message which is a Request
		(*writer) << "<RequestMessage>";
		(*writer) << r->name;
		writer->Flush();
	
		(*writer) << "<Level>";
		(*writer) << r->level;
		writer->Flush();
		
		// send across the number of the parameters in the Message
		int numberOfParameters = r->parameters.GetCount();
		(*writer) << numberOfParameters;
		writer->Flush();
		POSITION pos;
		CString nameOfParameter;
		C2Object *valueOfParameter;
		for( pos = r->parameters.GetStartPosition(); pos != NULL; )
		{
			r->parameters.GetNextAssoc( pos, nameOfParameter, (CObject *&)valueOfParameter);
			// send across the name of the parameter
			(*writer) << nameOfParameter;
			writer->Flush();
			// send across the value of the parameter
			(*writer) << valueOfParameter;
			writer->Flush();
		}
		connStatus = TBC_STATE_ACTIVE;
		timeLastActive = (long) CTime::GetCurrentTime().GetTime();
		//System.out.println("successful write of request "+r.name);
//	}
//	catch(IOException ioe)
//	{
//		this.close();
//		connStatus=INACTIVE;
//		this.reconnect();
//	}
}

void Connection::teardown()
{
//	try 
//	{
		long now = (long) CTime::GetCurrentTime().GetTime();
		startInactive = now;
		timeConnected += now - startActive;
		writer->Close();
		reader->Close();
		socketFile->Close();
		socket.Close();
		readConn->stopWorking();
//	}
//	catch (Exception e)
//	{
//		System.out.println("TBC Connection: Caught exception in teardown() " + e.toString());
//	}
}

void Connection::newNotificationArrived(Notification *n)
{
	long now = (long) CTime::GetCurrentTime().GetTime();
	timeLastActive = now;
	topConnector->handle(n);
}
