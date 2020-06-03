// Component.cpp: implementation of the Component class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Component.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(Component, Brick)

Component::Component() : Brick()
{
	top = NULL;
	bottom = NULL;
	side = NULL;
}

Component::~Component()
{
}

Component::Component(CString n) : Brick(n)
{
	top = NULL;
	bottom = NULL;
	side = NULL;
}

Component::Component(Component &adr) {
	top = adr.top;
	bottom = adr.bottom;
	side = adr.side;
}

Component& Component::operator=(Component& rhs) {
	top = rhs.top;
	bottom = rhs.bottom;
	side = rhs.side;
	return *this;
}

void Component::send(Request& ir)
{
	// the objects are created here and destroyed by the framework after processing the messages.
	Request *r = new Request(ir);
	r->sourceId = topId;
	r->via = (CObject *)top;
//	messageFIFO->add((Message*)r);
	add(r);
	ArchitectureEvent reqSent(topId, ARCHEVENT_NAMES_REQSENT, 1);
	reqSent.addEventDescriptor(0, r->targetId);
	fireEvent(&reqSent);
}

void Component::send(Notification& in)
{
	Notification *n = new Notification(in);
	n->sourceId = bottomId;
	n->via = (CObject *)bottom;
//	messageFIFO->add((Message*)n);
	add(n);
	ArchitectureEvent notifSent(bottomId, ARCHEVENT_NAMES_NOTIFSENT, 1);
	notifSent.addEventDescriptor(0, n->targetId);
	fireEvent(&notifSent);
}

void Component::send(Peer& ip)
{
	Peer *p = new Peer(ip);
	p->sourceId = sideId;
	p->via = (CObject *)side;
//	messageFIFO->add((Message*)n);
	add(p);
	ArchitectureEvent peerSent(sideId, ARCHEVENT_NAMES_PEERSENT, 1);
	peerSent.addEventDescriptor(0, p->targetId);
	fireEvent(&peerSent);
}

void Component::handle(Request& r)
{
	//should be overloaded to handle requests
}

void Component::handle(Notification& n)
{
	//should be overloaded to handle notifications
}

void Component::handle(Peer& p)
{
	//should be overloaded to handle notifications
}

void Component::handle(Message& m) {
	if (m.type == MESSAGE_TYPE_REQUEST)
	{
		handle((Request&)m);
	}
	else if (m.type == MESSAGE_TYPE_NOTIFICATION)
	{
		handle ((Notification&)m);
	}
	else if (m.type == MESSAGE_TYPE_PEER)
	{
		handle ((Peer&)m);
	}
}

bool Component::hasTop() {
	return (top != NULL);
}

bool Component::hasBottom() {
	return (bottom != NULL);
}

bool Component::hasSide() {
	return (side != NULL);
}

CObject* Component::getTop() {
	return (CObject *)top;
}

CObject* Component::getBottom() {
	return (CObject *)bottom;
}

CObject* Component::getSide() {
	return (CObject *)side;
}

void Component::setTop(Connector* conn) {
	top = conn;
}

void Component::setBottom(Connector* conn) {
	bottom = conn;
}

void Component::setSide(PeerConnector* conn) {
	side = conn;
}

void Component::setBottomFree() {
	bottom = NULL;
}

void Component::setTopFree() {
	top = NULL;
}

void Component::setSideFree() {
	side = NULL;
}

Component::operator char*() {
	static char buff[256];
	strcpy(buff,"Component: ");
	strcat(buff,(char *)((LPCTSTR)name));
	strcat(buff,"\n");
	return buff;
}

