// C2Object.h: interface for the C2Object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_C2OBJECT_H__2DFA9778_CEF3_465B_A1DB_AD8F66AE0020__INCLUDED_)
#define AFX_C2OBJECT_H__2DFA9778_CEF3_465B_A1DB_AD8F66AE0020__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afx.h"

class AFX_EXT_CLASS C2Object : public CObject  
{
	DECLARE_SERIAL(C2Object)
public:
	C2Object();
	virtual ~C2Object();
	C2Object(C2Object &adr);
	virtual C2Object& operator=(C2Object& rhs);
	virtual C2Object* clone();
};

#endif // !defined(AFX_C2OBJECT_H__2DFA9778_CEF3_465B_A1DB_AD8F66AE0020__INCLUDED_)
