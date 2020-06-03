// Monitor.cpp: implementation of the Monitor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Monitor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Monitor::Monitor()
{

}

Monitor::~Monitor()
{

}

Monitor::Monitor(Monitor &adr) {
}

Monitor& Monitor::operator=(Monitor& rhs) {
	return *this;
}
