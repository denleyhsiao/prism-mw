// Request.cpp: implementation of the Request class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Request.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( Request, Message )

Request::Request() : Message()
{
	this->type = MESSAGE_TYPE_REQUEST;
}

Request::~Request()
{
}

Request::Request(CString Name) : Message(Name)
{
	this->type = MESSAGE_TYPE_REQUEST;
}

Request::Request(CString Name, Address* src) : Message(Name,src)
{
	this->type = MESSAGE_TYPE_REQUEST;
}

Request::Request(Request &adr) {
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

Request& Request::operator=(Request& rhs) {
	return *this;
}
