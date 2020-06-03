// AcceptConnectionThread.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "AcceptConnectionThread.h"
#include "BottomBorderConnector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AcceptConnectionThread

IMPLEMENT_DYNCREATE(AcceptConnectionThread, CWinThread)

AcceptConnectionThread::AcceptConnectionThread()
{
}

AcceptConnectionThread::~AcceptConnectionThread()
{
}

AcceptConnectionThread::AcceptConnectionThread(Connection *conn, Connector *parent, CArchive *rdr) : CWinThread()
{
	connection = conn;
	parentConnector = (BottomBorderConnector*) parent;
	keepWorking = true;
	reader = rdr;
}

BOOL AcceptConnectionThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int AcceptConnectionThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(AcceptConnectionThread, CWinThread)
	//{{AFX_MSG_MAP(AcceptConnectionThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AcceptConnectionThread message handlers

int AcceptConnectionThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
//	try
//	{
		CString line;
		while (keepWorking) 
			{
				(*reader) >> line;
				if(line == "<RequestMessage>")
				{									
					/*	unmarshalling of the Message object
					 *	assumption that BBC receives only Requests from accross the socket
					 */
					// read the name of the request
					(*reader) >> line;
					Request reqMsg(line);
					(*reader) >> line; // <Level>
					(*reader) >> reqMsg.level;
					// read the number of Parameters in the Message
					int noOfParas;
					(*reader) >> noOfParas;
					CString nameOfParam;
					C2Object *valueOfParam;
					for(int i=0; i<noOfParas; i++)
					{
						(*reader) >> nameOfParam;
						(*reader) >> valueOfParam;
						reqMsg.addParameter(nameOfParam, *valueOfParam);
					}
					parentConnector->handle(&reqMsg);
				}
			}       // end while ()
//	}
//	catch (Exception e) 
//	{
//		System.out.println("exception in reading from socket. Connection ID:"+ connection.ID+" e:"+e.toString());
//	}
	
	//return CWinThread::Run();
	return 0;
}

void AcceptConnectionThread::stopWorking () {
	keepWorking = false;
}