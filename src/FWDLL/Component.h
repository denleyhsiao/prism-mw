// Component.h: interface for the Component class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENT_H__F9B5F9CE_FA6C_442F_AB57_04FBD2DC4CF2__INCLUDED_)
#define AFX_COMPONENT_H__F9B5F9CE_FA6C_442F_AB57_04FBD2DC4CF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"
#include "ArchitectureEvent.h"

class Connector;
class PeerConnector;

class AFX_EXT_CLASS Component : public Brick  
{
	DECLARE_DYNAMIC( Component )
protected:
	Connector* top;
	Connector* bottom;
	PeerConnector* side;

public:
	Component();
	Component(CString n);
	virtual ~Component();
	Component(Component &adr);
	Component& operator=(Component& rhs);

public:
	virtual void send(Notification& n);
	virtual void send(Request& r);
	virtual void send(Peer& p);
	virtual void handle(Request& r);
	virtual void handle(Notification& n);
	virtual void handle(Peer& p);
	virtual void handle(Message& m);

	bool hasTop();
	bool hasBottom();
	bool hasSide();
	CObject* getTop();
	CObject* getBottom();
	CObject* getSide();
	void setTop(Connector* conn);
	void setBottom(Connector* conn);
	void setSide(PeerConnector* conn);
	void setBottomFree();
	void setTopFree();
	void setSideFree();
	virtual operator char*();

};

#endif // !defined(AFX_COMPONENT_H__F9B5F9CE_FA6C_442F_AB57_04FBD2DC4CF2__INCLUDED_)
