// EventObject.cpp: implementation of the EventObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EventObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EventObject::EventObject()
{
}

EventObject::~EventObject()
{
}

EventObject::EventObject(CObject* source) {
    this->source = source;
}

EventObject::EventObject(EventObject &adr) {
    this->source = adr.source;
}

EventObject& EventObject::operator=(EventObject& rhs) {
    this->source = rhs.source;
	return *this;
}

CObject* EventObject::getSource() {
	return source;
}

EventObject::operator char*() {
	static char buff[256];
	strcpy(buff,"EventObject: [source=");
	strcat(buff,(char *)source);
    return buff;
}

