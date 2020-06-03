// FIFODispatch.h: interface for the FIFODispatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIFODISPATCH_H__6A037EE5_06BB_42DD_A50C_BB66D724502A__INCLUDED_)
#define AFX_FIFODISPATCH_H__6A037EE5_06BB_42DD_A50C_BB66D724502A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Synchronization.h"
#include "Dispatch.h"

#define DEFAULT_SIZE	250

class AFX_EXT_CLASS FIFODispatch : public Dispatch  
{
	DECLARE_SYNCHRONIZED()
	DECLARE_WAIT_NOTIFY()
private:
	int emptySlots;
public:
	CObject** queue;
	int size;
	int head;
	int tail;

public:
	FIFODispatch();
	FIFODispatch(int FIFOSize);
	~FIFODispatch();
	FIFODispatch(FIFODispatch &adr);
	FIFODispatch& operator=(FIFODispatch& rhs);

	virtual void add(Message* m);
	virtual Message* getMessage();
	virtual int getWaitingLength();
	virtual void setMessageCapacity(int n);
	operator char*();

private:
	bool isQueueEmpty();
	bool isQueueFull();
	void incrementTail();
	void incrementHead();

};

#endif // !defined(AFX_FIFODISPATCH_H__6A037EE5_06BB_42DD_A50C_BB66D724502A__INCLUDED_)
