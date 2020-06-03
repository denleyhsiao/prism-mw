// Request.h: interface for the Request class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REQUEST_H__A843E2DC_E280_4AC0_8966_5646DCB56FF4__INCLUDED_)
#define AFX_REQUEST_H__A843E2DC_E280_4AC0_8966_5646DCB56FF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"

class AFX_EXT_CLASS Request : public Message  
{
	DECLARE_DYNAMIC( Request )
public:
	Request(CString Name);
	Request();
	virtual ~Request();
	Request(CString Name, Address* src);
	Request(Request &adr);
	Request& operator=(Request& rhs);
};
#endif // !defined(AFX_REQUEST_H__A843E2DC_E280_4AC0_8966_5646DCB56FF4__INCLUDED_)
