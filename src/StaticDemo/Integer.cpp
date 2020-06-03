// Integer.cpp: implementation of the CInteger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Integer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInteger::CInteger()
{
}

CInteger::~CInteger()
{
}

CInteger::CInteger(int v)
{
value=v;
}

CInteger::CInteger(CInteger &adr) {
	this->value = adr.value;
}

CInteger& CInteger::operator=(CInteger& rhs) {
	this->value = rhs.value;
	return *this;
}

C2Object* CInteger::clone() {
	CInteger* pobj = new CInteger(value);
	return pobj;
}
