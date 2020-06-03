// CompA.h: interface for the CompA class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPA_H__D892B312_BF05_46A6_B8B9_A57E5E780884__INCLUDED_)
#define AFX_COMPA_H__D892B312_BF05_46A6_B8B9_A57E5E780884__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\FWDLL\FWDLL.h"
#include "..\StaticDemo\Integer.h"

class CBorderDemoDlg;

class CompA : public Component  
{
public:
	CBorderDemoDlg* dlg;
	int  left;
	int  right;
	int  res;
	CompA();
	virtual ~CompA();
	virtual void handle(Notification& n);
	void add();
	void div();
	void mul();
	void sub();
};

#endif // !defined(AFX_COMPA_H__D892B312_BF05_46A6_B8B9_A57E5E780884__INCLUDED_)
