// Connector.cpp: implementation of the Connector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Connector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(Connector,Brick)

IMPLEMENT_SYNCHRONIZED(Connector)

Connector::Connector()
{
	lTop=new CObList(5);
	lBottom=new CObList(5);
}

Connector::~Connector()
{
	if(lBottom != NULL)
		delete lBottom;
	if(lTop != NULL) 
		delete lTop;
}

Connector::Connector(CString n) : Brick(n)
{
	lTop=new CObList(5);
	lBottom=new CObList(5);
}

Connector::Connector(Connector &adr) {
	lTop=new CObList(5);
	lBottom=new CObList(5);
	POSITION pos;
	for( pos = adr.lTop->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)adr.lTop->GetNext( pos );
		lTop->AddTail(b);
	}
	for( pos = adr.lBottom->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)adr.lBottom->GetNext( pos );
		lBottom->AddTail(b);
	}
}

Connector& Connector::operator=(Connector& rhs) {
	if(lBottom != NULL)
		delete lBottom;
	if(lTop != NULL) 
		delete lTop;
	lTop=new CObList(5);
	lBottom=new CObList(5);
	POSITION pos;
	for( pos = rhs.lTop->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)rhs.lTop->GetNext( pos );
		lTop->AddTail(b);
	}
	for( pos = rhs.lBottom->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)rhs.lBottom->GetNext( pos );
		lBottom->AddTail(b);
	}
	return *this;
}

void Connector::handle(Request* r)
{
	ENTER_SYNCHRONIZED()
	ArchitectureEvent reqRecd(topId, ARCHEVENT_NAMES_REQRECD, 1);
	reqRecd.addEventDescriptor(0,r);
	fireEvent(&reqRecd);

	POSITION pos;
	for( pos = lTop->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)lTop->GetNext( pos );
		handleRequest(b,r);
	}
	LEAVE_SYNCHRONIZED()
}

void Connector::handle(Notification* n)
{
	ENTER_SYNCHRONIZED()
	ArchitectureEvent notifRecd(topId, ARCHEVENT_NAMES_NOTIFRECD, 1);
	notifRecd.addEventDescriptor(0, n);
	fireEvent(&notifRecd);

	POSITION pos;
	for( pos = lBottom->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)lBottom->GetNext( pos );
		handleNotification(b,n);
	}
	LEAVE_SYNCHRONIZED()
}

void Connector::handle(Message* m) {
	if (m->type == MESSAGE_TYPE_REQUEST)
	{
		handle((Request*)m);
	}
	else if (m->type == MESSAGE_TYPE_NOTIFICATION)
	{
		handle((Notification*)m);
	}
}

void Connector::handleRequest(Brick* b, Request* r) {
	ArchitectureEvent reqBeingHdld(topId, ARCHEVENT_NAMES_REQBEINGHDLD, 2);
	reqBeingHdld.addEventDescriptor(0, b);
	reqBeingHdld.addEventDescriptor(1, r);
	fireEvent(&reqBeingHdld);

	b->handle(*r);

	ArchitectureEvent reqHdld(topId, ARCHEVENT_NAMES_REQHDLD, 2);
	reqHdld.addEventDescriptor(0, b);
	reqHdld.addEventDescriptor(1, r);
	fireEvent(&reqHdld);
}

void Connector::handleNotification(Brick* b, Notification* n) {
	ArchitectureEvent notifBeingHdld(topId, ARCHEVENT_NAMES_NOTIFBEINGHDLD, 2);
	notifBeingHdld.addEventDescriptor(0, b);
	notifBeingHdld.addEventDescriptor(1, n);
	fireEvent(&notifBeingHdld);

	b->handle(*n);
	
	ArchitectureEvent notifHdld(topId, ARCHEVENT_NAMES_NOTIFHDLD, 2);
	notifHdld.addEventDescriptor(0, b);
	notifHdld.addEventDescriptor(1, n);
	fireEvent(&notifHdld);
}

void Connector::addToTop(Brick* t) {
	ENTER_SYNCHRONIZED()
	lTop->AddTail(t);
	LEAVE_SYNCHRONIZED()
}

void Connector::addToBottom(Brick* b) {
	ENTER_SYNCHRONIZED()
	lBottom->AddTail(b);
	LEAVE_SYNCHRONIZED()
}

void Connector::removeFromTop(Brick* t) {
	ENTER_SYNCHRONIZED()
	POSITION pos = lTop->Find(t);
	if(pos != NULL) lTop->RemoveAt(pos);
	LEAVE_SYNCHRONIZED()
}

void Connector::removeFromBottom(Brick* b) {
	ENTER_SYNCHRONIZED()
	POSITION pos = lBottom->Find(b);
	if(pos != NULL) lBottom->RemoveAt(pos);
	LEAVE_SYNCHRONIZED()
}

bool Connector::hasTop() {
	return (lTop->GetCount() != 0);
}

bool Connector::hasBottom() {
	return (lBottom->GetCount() != 0);
}

CObject* Connector::getTop() {
	return lTop;
}

CObject* Connector::getBottom() {
	return lBottom;
}

char* Connector::toString(bool recurse) {
	static char buff[1024];
	strcpy(buff,"Connector: ");
	strcat(buff,(char *)(LPCTSTR)name);
	if (!recurse) {
		strcat(buff,"\n");
		return buff;
	}

	strcat(buff,"\n\tTop Components: \n");
	Brick* b;
	POSITION pos = lTop->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lTop->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(Component))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)(LPCTSTR)b);
		}
	}
	strcat(buff,"\n\tTop Connectors: \n");
	pos = lTop->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lTop->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(Connector))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)((Connector*)b)->toString(false));
		}
	}

	strcat(buff,"\n\tBottom Components: \n");
	pos = lBottom->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lBottom->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(Component))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)(LPCTSTR)b);
		}
	}
	strcat(buff,"\n\tBottom Connectors: \n");
	pos = lBottom->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lBottom->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(Connector))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)((Connector*)b)->toString(false));
		}
	}

	return buff;
}

Connector::operator char*() {
	return toString(true);
}
