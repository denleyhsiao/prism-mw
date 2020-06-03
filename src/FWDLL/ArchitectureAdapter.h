// ArchitectureAdapter.h: interface for the ArchitectureAdapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARCHITECTUREADAPTER_H__834F97F8_7D86_4739_8673_ABD2384F88BA__INCLUDED_)
#define AFX_ARCHITECTUREADAPTER_H__834F97F8_7D86_4739_8673_ABD2384F88BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Architecture.h"

class AFX_EXT_CLASS ArchitectureAdapter : public Architecture  
{
public:
	ArchitectureAdapter();
	virtual ~ArchitectureAdapter();

public:
	ArchitectureAdapter(CString name);
	ArchitectureAdapter(ArchitectureAdapter &adr);
	ArchitectureAdapter& operator=(ArchitectureAdapter& rhs);

	virtual bool hasTop();
	virtual bool hasBottom();
	virtual bool hasSide();
	virtual CObject* getTop();
	virtual CObject* getBottom();
	virtual CObject* getSide();
	virtual void setTop(Connector* conn);
	virtual void setBottom(Connector* conn);
	virtual void setSide(PeerConnector* conn);
	virtual void addToTop(Brick* top);
	virtual void addToBottom(Brick* bottom);
	virtual void addToSide(Brick* side);
	virtual void removeFromTop(Brick* top);
	virtual void removeFromBottom(Brick* bottom);
	virtual void removeFromSide(Brick* side);
	virtual void send(Request* r);
	virtual void send(Notification* n);
	virtual void send(Peer* p);

};

#endif // !defined(AFX_ARCHITECTUREADAPTER_H__834F97F8_7D86_4739_8673_ABD2384F88BA__INCLUDED_)
