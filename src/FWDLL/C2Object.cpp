// C2Object.cpp: implementation of the C2Object class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "C2Object.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(C2Object,CObject,0)

C2Object::C2Object()
{
}

C2Object::~C2Object()
{
}

C2Object::C2Object(C2Object &adr) {
}

C2Object& C2Object::operator=(C2Object& rhs) {
	return *this;
}

C2Object* C2Object::clone() {
	return new C2Object();
}
