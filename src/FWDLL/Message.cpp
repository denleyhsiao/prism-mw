// Message.cpp: implementation of the Message class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Afxtempl.h"
#include "Message.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( Message, CObject)
IMPLEMENT_STATIC_SYNCHRONIZED(Message)

Message::Message()
{
	id = getNextId();
	parameters.InitHashTable(257);//for best performance hash table should be initialized with a prime number (such as 257)
	name = "Message";
	sourceId = NULL;
}

Message::~Message()
{
}

Message::Message(CString Name)
{
	name = Name;
	id = getNextId();
	parameters.InitHashTable(300);
	sourceId = NULL;
}

Message::Message(CString Name, Address* src)
{
	name = Name;
	id = getNextId();
	parameters.InitHashTable(300);
	sourceId = src;
}

Message::Message(Message &adr) {
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

Message& Message::operator=(Message& rhs) {
	name = rhs.name;
	id = rhs.id;
	parameters.InitHashTable(300);
	POSITION pos = rhs.parameters.GetStartPosition();
	CString key; CObject* value;
	while (pos != NULL)
	{
		rhs.parameters.GetNextAssoc( pos, key, value );
		parameters.SetAt(key,value);
	}
	level = rhs.level;
	sourceId = rhs.sourceId;
	targetId = rhs.targetId;
	subSourceId = rhs.subSourceId;
	subTargetId = rhs.subTargetId;
	type = rhs.type;
	via = rhs.via;
	return *this;
}

long Message::getNextId() {
	static long nextId = 0;
	ENTER_STATIC_SYNCHRONIZED()
	nextId++;
	LEAVE_STATIC_SYNCHRONIZED()
	return nextId-1;
}

void Message::addParameter(CString parameterName, C2Object& parameterValue)
{
	C2Object *obj = parameterValue.clone();
	parameters.SetAt(parameterName,obj);
}

bool Message::hasParameter(CString Name)
{
	CObject* obj;
	return((bool)(parameters.Lookup(Name, obj))); 
}

void Message::removeParameter(CString Name)
{
	parameters.RemoveKey(Name);
}

C2Object* Message::getParameter(CString Name)
{
	CObject* obj;
	if (parameters.Lookup(Name,obj))
	{
	return((C2Object *)obj);
	}
	else return (NULL);
}

void Message::destructParameters()
{
	POSITION pos = parameters.GetStartPosition();
	CString key; CObject* value;
	while (pos != NULL)
	{
		parameters.GetNextAssoc( pos, key, value );
		delete value;
	}
}

Message::operator char*() {
	static char buff[256];
	char temp[80];
	strcpy(buff,"#");
	_itoa(id,temp,10);
	strcat(buff,temp);
	strcat(buff,":");
	strcat(buff,(char *)((LPCTSTR)name));
	return buff;
}