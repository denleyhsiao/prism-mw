// Peer.h: interface for the Peer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEER_H__7AFFE919_C3C7_4A5F_B23D_3177F0D81A83__INCLUDED_)
#define AFX_PEER_H__7AFFE919_C3C7_4A5F_B23D_3177F0D81A83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"

class AFX_EXT_CLASS Peer : public Message  
{
	DECLARE_DYNAMIC( Peer )
public:
	Peer();
	Peer(CString Name);
	virtual ~Peer();
	Peer(CString Name, Address* src);
	Peer(Peer &adr);
	Peer& operator=(Peer& rhs);
};

#endif // !defined(AFX_PEER_H__7AFFE919_C3C7_4A5F_B23D_3177F0D81A83__INCLUDED_)
