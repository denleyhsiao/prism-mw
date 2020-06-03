// Message.h: interface for the Message class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESSAGE_H__3268553A_05D1_4B46_AF60_DDD68B76C076__INCLUDED_)
#define AFX_MESSAGE_H__3268553A_05D1_4B46_AF60_DDD68B76C076__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afx.h"
#include "Afxcoll.h"
#include "Synchronization.h"
#include "Address.h"
#include "C2Object.h"

#define MESSAGE_TYPE_REQUEST		1
#define MESSAGE_TYPE_NOTIFICATION	2
#define MESSAGE_TYPE_PEER			3

class AFX_EXT_CLASS Message : public CObject
{
	DECLARE_DYNAMIC( Message )
	DECLARE_STATIC_SYNCHRONIZED()
public:
	long id;
	long level;
	int type;
	Address* targetId;
	Address* subTargetId;
	CString name;
	Address* sourceId;
	Address* subSourceId;
    CObject* via;
	CMapStringToOb parameters;

public:
	static long getNextId();
	C2Object* getParameter(CString Name);
	void removeParameter(CString Name);
	bool hasParameter(CString Name);
	virtual void addParameter(CString parameterName, C2Object& parameterValue);
	Message();
	Message(CString Name);
	Message(CString Name, Address* src);
	virtual ~Message();
	Message(Message &adr);
	Message& operator=(Message& rhs);

	void destructParameters();

	virtual operator char*();
};


#endif // !defined(AFX_MESSAGE_H__3268553A_05D1_4B46_AF60_DDD68B76C076__INCLUDED_)
