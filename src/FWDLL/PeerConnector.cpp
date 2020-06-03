// PeerConnector.cpp: implementation of the PeerConnector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeerConnector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(PeerConnector,Brick)
IMPLEMENT_SYNCHRONIZED(PeerConnector)

PeerConnector::PeerConnector()
{

}

PeerConnector::~PeerConnector()
{
	if(lPeer != NULL)
		delete lPeer;
}

PeerConnector::PeerConnector(CString str) : Brick(str) {
		lPeer = new CObList(5);
}

PeerConnector::PeerConnector(PeerConnector &adr) {
	lPeer=new CObList(5);
	POSITION pos;
	for( pos = adr.lPeer->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)adr.lPeer->GetNext( pos );
		lPeer->AddTail(b);
	}
}

PeerConnector& PeerConnector::operator=(PeerConnector& rhs) {
	if(lPeer != NULL)
		delete lPeer;
	lPeer=new CObList(5);
	POSITION pos;
	for( pos = rhs.lPeer->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)rhs.lPeer->GetNext( pos );
		lPeer->AddTail(b);
	}
	return *this;
}

void PeerConnector::handle(Peer* p) {
	ENTER_SYNCHRONIZED()
	ArchitectureEvent peerRecd(sideId, ARCHEVENT_NAMES_PEERRECD, 1);
	peerRecd.addEventDescriptor(0, p);
	fireEvent(&peerRecd);
	// simply call handle's of all my components
	Brick* b;
	POSITION pos = lPeer->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lPeer->GetNext(pos);
		if (b->sideId!=p->sourceId)
		{
			handleSide(b, p);
		}
	}
	LEAVE_SYNCHRONIZED()
}

void PeerConnector::handleSide(Brick* b, Peer* p) {
	ArchitectureEvent peerBeingHdld(sideId, ARCHEVENT_NAMES_PEERBEINGHDLD, 2);
	peerBeingHdld.addEventDescriptor(0, b);
	peerBeingHdld.addEventDescriptor(1, p);
	fireEvent(&peerBeingHdld);
	
	b->handle(*p);

	ArchitectureEvent peerHdld(sideId, ARCHEVENT_NAMES_PEERHDLD, 2);
	peerHdld.addEventDescriptor(0, b);
	peerHdld.addEventDescriptor(1, p);
	fireEvent(&peerHdld);
}

void PeerConnector::addToSide(Brick* t) {
	ENTER_SYNCHRONIZED()
    lPeer->AddTail(t);
	LEAVE_SYNCHRONIZED()
}

void PeerConnector::removeFromSide(Brick* t) {
	ENTER_SYNCHRONIZED()
	POSITION pos = lPeer->Find(t);
	lPeer->RemoveAt(pos);
	LEAVE_SYNCHRONIZED()
}

bool PeerConnector::hasSide() {
	return (lPeer->GetCount() != 0);
}

CObject* PeerConnector::getSide() {
	return lPeer;
}

char* PeerConnector::toString(bool recurse) {
	static char buff[1024];
	strcpy(buff,"Connector: ");
	strcat(buff,(char *)(LPCTSTR)name);
	if (!recurse) {
		strcat(buff,"\n");
		return buff;
	}

	strcat(buff,"\n\tSide Components: \n");
	Brick* b;
	POSITION pos = lPeer->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lPeer->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(Component))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)b);
		}
	}
	strcat(buff,"\n\tSide Connectors: \n");
	pos = lPeer->GetHeadPosition();
	while(pos != NULL)
	{
		b = (Brick*)lPeer->GetNext(pos);
		if(b->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
			strcat(buff,"\t\t ");
			strcat(buff,(char *)((PeerConnector*)b)->toString(false));
		}
	}

	return buff;
}

PeerConnector::operator char*() {
	return toString(true);
}

void PeerConnector::handle(Message* m)
{
	if (m->type == MESSAGE_TYPE_PEER)
	{
		this->handle((Peer*)m);
	}
}
