// PeerConnector.h: interface for the PeerConnector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEERCONNECTOR_H__B8AE3A5B_B3E6_45FB_B8E0_F3C192297DB9__INCLUDED_)
#define AFX_PEERCONNECTOR_H__B8AE3A5B_B3E6_45FB_B8E0_F3C192297DB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Synchronization.h"
#include "Brick.h"
#include "ArchitectureEvent.h"
#include "Component.h"

class AFX_EXT_CLASS PeerConnector : public Brick  
{
	DECLARE_DYNAMIC(PeerConnector)
	DECLARE_SYNCHRONIZED()
protected:
	CObList*	lPeer;

public:
	PeerConnector();
	virtual ~PeerConnector();
	PeerConnector(CString str);
	PeerConnector(PeerConnector &adr);
	PeerConnector& operator=(PeerConnector& rhs);

	void handle(Peer* p);
	void handleSide(Brick* b, Peer* p);
	void addToSide(Brick* t);
	void removeFromSide(Brick* t);
	bool hasSide();
	CObject* getSide();
	char* toString(bool recurse);
	virtual operator char*();
	void handle(Message* m);
};

#endif // !defined(AFX_PEERCONNECTOR_H__B8AE3A5B_B3E6_45FB_B8E0_F3C192297DB9__INCLUDED_)
