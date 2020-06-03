// CompB.h: interface for the CompB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPB_H__73393D3B_3069_4D83_AD45_1912EC8F81BF__INCLUDED_)
#define AFX_COMPB_H__73393D3B_3069_4D83_AD45_1912EC8F81BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\FWDLL\FWDLL.h"
#include "Integer.h"

class CompB : public Component  
{
public:
	CompB();
	virtual ~CompB();
	virtual void handle (Request& r);
};

#endif // !defined(AFX_COMPB_H__73393D3B_3069_4D83_AD45_1912EC8F81BF__INCLUDED_)
