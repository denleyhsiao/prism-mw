// Brick.h: interface for the Brick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRICK_H__FF651ECD_133B_4D3F_852D_76FF8644D8C2__INCLUDED_)
#define AFX_BRICK_H__FF651ECD_133B_4D3F_852D_76FF8644D8C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afx.h"
#include "Afxcoll.h"

#include "Request.h"
#include "Notification.h"
#include "Peer.h"
#include "ArchitectureEvent.h"
#include "Scaffold.h"

class SynchronizedFIFO;

class AFX_EXT_CLASS Brick : public CObject
{
	DECLARE_DYNAMIC(Brick)
public:
	CString name;
    Address* myId;
	Address* topId;
	Address* bottomId;
	Address* sideId;
	Scaffold* scaffold;

public:
	void create(CString s);
	virtual void start();
	virtual void handle(Request& r);
	virtual void handle(Notification& n);
	virtual void handle(Peer& p);
	Brick(CString n);
	Brick();
	virtual ~Brick();
	Brick(Brick &adr);
	Brick& operator=(Brick& rhs);

	virtual void setScaffold(Scaffold* scaffold);
	virtual void setTopId(Address* id);
	virtual Address* getTopId();
	virtual void setSideId(Address* id);
	virtual Address* getSideId();
	virtual void setBottomId(Address* id);
	virtual Address* getBottomId();
	virtual void fireEvent(ArchitectureEvent* event);
	virtual void add(Message* message);
	virtual void setName(CString n);
	virtual operator char*();
};

#endif // !defined(AFX_BRICK_H__FF651ECD_133B_4D3F_852D_76FF8644D8C2__INCLUDED_)
