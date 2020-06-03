// ArchitectureEvent.cpp: implementation of the ArchitectureEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ArchitectureEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_STATIC_SYNCHRONIZED(ArchitectureEvent)

ArchitectureEvent::ArchitectureEvent()
{
	eventDescriptors = NULL;
	descriptorCount = 0;
}

ArchitectureEvent::~ArchitectureEvent()
{
	if(eventDescriptors != NULL)
		delete [] eventDescriptors;
}


long ArchitectureEvent::getNextId() 	{
	static long nextId = 0;
	ENTER_STATIC_SYNCHRONIZED()
	++nextId;
	LEAVE_STATIC_SYNCHRONIZED()
	return nextId;
}

ArchitectureEvent::ArchitectureEvent(Address* source, CString name) : EventObject(source) {
	eventDescriptors = NULL;
    this->name = name;
    id = getNextId();
	descriptorCount = 0;
}

ArchitectureEvent::ArchitectureEvent(Address* source, CString name, int descriptorCount) : EventObject(source) {
	eventDescriptors = NULL;
    this->name = name;
	this->descriptorCount = descriptorCount;
    id = getNextId();
    if (descriptorCount > 0)
		eventDescriptors = new CObject*[descriptorCount];
}

ArchitectureEvent::ArchitectureEvent(ArchitectureEvent &adr) {
	name = adr.name;
	id = adr.id;
	descriptorCount = adr.descriptorCount;
	eventDescriptors = new CObject*[descriptorCount];
	for(int i=0; i<descriptorCount;i++) {
		eventDescriptors[i] = adr.eventDescriptors[i];
	}
}

ArchitectureEvent& ArchitectureEvent::operator=(ArchitectureEvent& rhs) {
	if(eventDescriptors != NULL)
		delete [] eventDescriptors;
	name = rhs.name;
	id = rhs.id;
	descriptorCount = rhs.descriptorCount;
	eventDescriptors = new CObject*[descriptorCount];
	for(int i=0; i<descriptorCount;i++) {
		eventDescriptors[i] = rhs.eventDescriptors[i];
	}
	return *this;
}

CObject** ArchitectureEvent::getEventDescriptors() {
	return eventDescriptors;
}

void ArchitectureEvent::addEventDescriptor(int index, CObject* descriptor) {
	if(index >= 0 && index < descriptorCount)
		eventDescriptors[index] = descriptor;
}

CObject* ArchitectureEvent::getEventDescriptor(int index) {
	if(index >= 0 && index < descriptorCount)
		return eventDescriptors[index];
	return NULL;
}
