// Address.h: interface for the Address class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDRESS_H__2A7F7E0C_BC0B_431E_BA37_1FDF6816E1F0__INCLUDED_)
#define AFX_ADDRESS_H__2A7F7E0C_BC0B_431E_BA37_1FDF6816E1F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afx.h"
#include "Afxcoll.h"


#define ADDRESS_DIGITS_IPSTYLE	4
#define ADDRESS_BASE_256		256
#define ADDRESS_DELIMITER_DOT	'.'

class AFX_EXT_CLASS Address : public CObject  
{
private:
	long id;

public:
	Address();
	virtual ~Address();
	Address(CString address);
	Address(Address &adr);
	Address& operator=(Address& rhs);

	Address(long newId);
	Address* nextAddress();
	Address* prevAddress();
	long getNumeric();

	bool operator==(Address another);
	bool operator==(long num);
	virtual operator char*();

};

#endif // !defined(AFX_ADDRESS_H__2A7F7E0C_BC0B_431E_BA37_1FDF6816E1F0__INCLUDED_)
