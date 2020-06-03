// Dispatch.h: interface for the Dispatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISPATCH_H__94C616E5_F49A_4F14_A836_F34B2DE040E1__INCLUDED_)
#define AFX_DISPATCH_H__94C616E5_F49A_4F14_A836_F34B2DE040E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"

class AFX_EXT_CLASS Dispatch  
{
public:
	Dispatch();
	virtual ~Dispatch();
	Dispatch(Dispatch &adr);
	Dispatch& operator=(Dispatch& rhs);

	virtual void add(Message* m) = 0;
	virtual int getWaitingLength() = 0;
	virtual Message* getMessage() = 0;
	virtual void setMessageCapacity(int n) = 0;
};

#endif // !defined(AFX_DISPATCH_H__94C616E5_F49A_4F14_A836_F34B2DE040E1__INCLUDED_)
