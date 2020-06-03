// Integer.h: interface for the CInteger class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTEGER_H__9916339B_677F_464D_8C51_586E92D00984__INCLUDED_)
#define AFX_INTEGER_H__9916339B_677F_464D_8C51_586E92D00984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\FWDLL\FWDLL.h"

class CInteger : public C2Object  
{
public:
	CInteger();
	CInteger(int v);
	virtual ~CInteger();
	CInteger(CInteger &adr);
	virtual CInteger& operator=(CInteger& rhs);
	virtual C2Object* clone();
	int value;
};

#endif // !defined(AFX_INTEGER_H__9916339B_677F_464D_8C51_586E92D00984__INCLUDED_)
