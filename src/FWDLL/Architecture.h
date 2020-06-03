// Architecture.h: interface for the Architecture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARCHITECTURE_H__5C85CEDE_D4BB_4F41_8024_A7C7B4900DAD__INCLUDED_)
#define AFX_ARCHITECTURE_H__5C85CEDE_D4BB_4F41_8024_A7C7B4900DAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* #define UPPER_BOUND 50
#define LOWER_BOUND 1
#define DEFAULT_COUNT 2
#include "Brick.h"


class C2Object;


class Component;
class Connector;
class Message;
class Request;
class Notification;
class Semaphor;

class SynchronizedFIFO; */

#include "Brick.h"
#include "Connector.h"
#include "PeerConnector.h"

class AFX_EXT_CLASS Architecture : public Brick  
{
	DECLARE_DYNAMIC( Architecture )
private:
	CObList* components;

public:
	Architecture();
	Architecture(CString str);
	~Architecture();
	Architecture(Architecture &adr);
	Architecture& operator=(Architecture& rhs);

	virtual void start();
	virtual void handle(Message& r);
	virtual void add(Brick* b);
	virtual void weld(Brick* b1, Brick* b2);
	virtual void unweld(Brick* b1, Brick* b2);
	virtual void peerWeld(Brick* b1, Brick* b2);
	virtual void peerUnweld(Brick* b1, Brick* b2);
	virtual void remove(Brick* b);
	virtual Brick* getReference(CString componentName);
	virtual operator char*();

};
#endif // !defined(AFX_ARCHITECTURE_H__5C85CEDE_D4BB_4F41_8024_A7C7B4900DAD__INCLUDED_)
