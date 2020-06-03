// Connector.h: interface for the Connector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTOR_H__F9957FB4_8FB2_4C97_AF70_D321CFED9B9B__INCLUDED_)
#define AFX_CONNECTOR_H__F9957FB4_8FB2_4C97_AF70_D321CFED9B9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BROADCAST 1

#include "Afxmt.h"
#include "Brick.h"
#include "ArchitectureEvent.h"
#include "Component.h"

class AFX_EXT_CLASS Connector : public Brick  
{
	DECLARE_DYNAMIC( Connector )
	DECLARE_SYNCHRONIZED()
public:
	CObList* lTop;
	CObList* lBottom;

public:
	void handle(Request* r);
	void handle(Notification* r);
	void handle(Message* m);
	Connector();
	Connector(CString n);
	virtual ~Connector();
	Connector(Connector &adr);
	Connector& operator=(Connector& rhs);

	virtual void handleRequest(Brick* b, Request* r);
	virtual void handleNotification(Brick* b, Notification* n);
	void addToTop(Brick* t);
	void addToBottom(Brick* b);
	void removeFromTop(Brick* t);
	void removeFromBottom(Brick* b);
	bool hasTop();
	bool hasBottom();
	CObject* getTop();
	CObject* getBottom();
	char* toString(bool recurse);
	virtual operator char*();

};

#endif // !defined(AFX_CONNECTOR_H__F9957FB4_8FB2_4C97_AF70_D321CFED9B9B__INCLUDED_)
