// Long.cpp: implementation of the Long class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Long.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Long::Long()
{
}

Long::~Long()
{
}

Long::Long(long v)
{
	value=v;
}

Long::Long(Long &adr) {
	this->value = adr.value;
}

Long& Long::operator=(Long& rhs) {
	this->value = rhs.value;
	return *this;
}

C2Object* Long::clone() {
	Long* pobj = new Long(value);
	return pobj;
}

long Long::getValue() {
	return value;
}
