// Notification.h: interface for the Notification class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTIFICATION_H__12742417_8C98_4939_9E63_57B51C87FFB9__INCLUDED_)
#define AFX_NOTIFICATION_H__12742417_8C98_4939_9E63_57B51C87FFB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"

class AFX_EXT_CLASS Notification : public Message  
{
	DECLARE_DYNAMIC( Notification )
public:
	Notification(CString Name);
	Notification();
	virtual ~Notification();
	Notification(CString Name, Address* src);
	Notification(Notification &adr);
	Notification& operator=(Notification& rhs);
};

#endif // !defined(AFX_NOTIFICATION_H__12742417_8C98_4939_9E63_57B51C87FFB9__INCLUDED_)
