// Address.cpp: implementation of the Address class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Address.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Address::Address() {
	id = -1;
}

Address::~Address() {
}

Address::Address(CString address) {
	long lastBase = 1;
	CString part("");
	for (int i = 0; i < ADDRESS_DIGITS_IPSTYLE; i++, lastBase *= ADDRESS_BASE_256) {
		int lastPart = address.GetLength();
		int nextPart = address.ReverseFind(ADDRESS_DELIMITER_DOT);
		if (nextPart != -1) {
			part = address.Mid(nextPart + 1, lastPart - nextPart - 1);
			address = address.Mid(0, nextPart);
		} else
			part = address;
		id += lastBase * atoi((char *)((LPCTSTR) part));
		lastPart = nextPart + 1;
	}
}

Address::Address(long newId) {
	id = newId;
}
	
Address::Address(Address &adr) {
	id = adr.id;
}

Address& Address::operator=(Address& rhs) {
	id = rhs.id;
	return *this;
}

Address::operator char*() {
	long l = id;
	static char buff[256];
	char temp[256];
	_itoa(l % ADDRESS_BASE_256,buff,10);
	for (int i = 1; i < ADDRESS_DIGITS_IPSTYLE; i++) {
		l /= ADDRESS_BASE_256;
		_itoa(l % ADDRESS_BASE_256,temp,10);
		strcat(temp,".");
		strcat(temp,buff);
		strcpy(buff,temp);
	}
	return buff;
}
	
bool Address::operator ==(Address another) {
	return another.id == id;
}

Address* Address::nextAddress() {
	return new Address(id + 1);
}

Address* Address::prevAddress() {
	return new Address(id - 1);
}

long Address::getNumeric() {
	return id;
}

bool Address::operator == (long num) {
	return id == num;
}

