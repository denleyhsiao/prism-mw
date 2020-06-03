// Long.h: interface for the Long class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LONG_H__CFB91CE9_FDFC_462E_A57B_B8B4A165AA20__INCLUDED_)
#define AFX_LONG_H__CFB91CE9_FDFC_462E_A57B_B8B4A165AA20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "C2Object.h"

class Long : public C2Object  
{
	long value;
public:
	Long();
	Long(long v);
	virtual ~Long();
public:
	Long(Long &adr);
	virtual Long& operator=(Long& rhs);
	virtual C2Object* clone();
	long getValue();
};

#endif // !defined(AFX_LONG_H__CFB91CE9_FDFC_462E_A57B_B8B4A165AA20__INCLUDED_)
