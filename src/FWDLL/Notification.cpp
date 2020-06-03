// Notification.cpp: implementation of the Notification class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Notification.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( Notification, Message )


Notification::Notification() : Message()
{
	this->type = MESSAGE_TYPE_NOTIFICATION;
}

Notification::~Notification()
{
}

Notification::Notification(CString Name) : Message(Name)
{
	this->type = MESSAGE_TYPE_NOTIFICATION;
}

Notification::Notification(CString Name, Address* src) : Message(Name,src)
{
	this->type = MESSAGE_TYPE_NOTIFICATION;
}

Notification::Notification(Notification &adr) {
	name = adr.name;
	id = adr.id;
	parameters.InitHashTable(300);
	POSITION pos = adr.parameters.GetStartPosition();
	CString key; CObject* value;
	while (pos != NULL)
	{
		adr.parameters.GetNextAssoc( pos, key, value );
		parameters.SetAt(key,value);
	}
	level = adr.level;
	sourceId = adr.sourceId;
	targetId = adr.targetId;
	subSourceId = adr.subSourceId;
	subTargetId = adr.subTargetId;
	type = adr.type;
	via = adr.via;
}

Notification& Notification::operator=(Notification& rhs) {
	return *this;
}
