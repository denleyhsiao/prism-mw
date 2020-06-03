// Scaffold.cpp: implementation of the Scaffold class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Scaffold.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Scaffold::Scaffold() {
	this->messageDispatch = NULL;
	this->monitor = NULL;
	this->scheduler = NULL;
}

Scaffold::~Scaffold() {
}

Scaffold::Scaffold(int type) {
	this->messageDispatch = NULL;
	this->monitor = NULL;
	this->scheduler = NULL;
    this->type = type;
}

Scaffold::Scaffold(Scaffold &adr) {
	this->messageDispatch = adr.messageDispatch;
	this->monitor = adr.monitor;
	this->scheduler = adr.scheduler;
    this->type = adr.type;
}

Scaffold& Scaffold::operator=(Scaffold& rhs) {
	this->messageDispatch = rhs.messageDispatch;
	this->monitor = rhs.monitor;
	this->scheduler = rhs.scheduler;
    this->type = rhs.type;
	return *this;
}

int Scaffold::getType() {
	return type;
}

void Scaffold::setDispatch(Dispatch* dispatch) {
    messageDispatch = dispatch;
	if (dispatch != NULL)
		type |= SCAFFOLD_TYPE_DISPATCH;
	else
		type ^= SCAFFOLD_TYPE_DISPATCH;
}

void Scaffold::setScheduler(Scheduler* sch) {
	scheduler = sch;
	if (scheduler != NULL)
		type |= SCAFFOLD_TYPE_SCHEDULER;
	else
		type ^= SCAFFOLD_TYPE_SCHEDULER;
}

void Scaffold::setMonitor(Monitor* mon) {
	monitor = mon;
	if (monitor != NULL)
		type |= SCAFFOLD_TYPE_MONITOR;
	else
		type ^= SCAFFOLD_TYPE_MONITOR;
}

void Scaffold::call(CString command, CObject* param) {
        call(command, param, true);
}

void Scaffold::call(CString command, CObject* param, boolean syncCall) {
	if (syncCall)
    {
		if (command == "add" && (type & SCAFFOLD_TYPE_DISPATCH) != 0)
        {
            messageDispatch->add((Message*) param);
        }
        else if (command == "see" && (type & SCAFFOLD_TYPE_MONITOR) != 0)
        {
            monitor->see((ArchitectureEvent*) param);
        }
    }
}
