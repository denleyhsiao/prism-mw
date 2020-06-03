// EventObject.h: interface for the EventObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENTOBJECT_H__3A337622_DD0B_471F_9A03_CE377F46BF21__INCLUDED_)
#define AFX_EVENTOBJECT_H__3A337622_DD0B_471F_9A03_CE377F46BF21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afx.h"

class EventObject : public CObject
{
protected:
	CObject*  source;
public:
	EventObject();
	virtual ~EventObject();
    EventObject(CObject* source);
	EventObject(EventObject &adr);
	EventObject& operator=(EventObject& rhs);

    CObject* getSource();
	virtual operator char*();
};

#endif // !defined(AFX_EVENTOBJECT_H__3A337622_DD0B_471F_9A03_CE377F46BF21__INCLUDED_)
