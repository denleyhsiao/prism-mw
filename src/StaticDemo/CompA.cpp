// CompA.cpp: implementation of the CompA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StaticDemo.h"
#include "CompA.h"
#include "StaticDemoDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CompA::CompA()
{
	this->name="A";
}

CompA::~CompA()
{
}

void CompA::add()
{
	Request r("Add");
	CInteger leftObj(left);
	CInteger rightObj(right);
	r.addParameter("left",leftObj);
	r.addParameter("right",rightObj);
	send(r);
}

void CompA::handle(Notification& n)
{
	CString tmp;
	if(n.name=="Result")
	{
		CInteger* r=(CInteger*)n.getParameter("result");
		res=r->value;
		dlg->Done();
	}
	else if (n.name=="ResultInvalid")
	{
		dlg->DisplayInvalidResult();
	}
}

void CompA::sub()
{
	Request r("Sub");
	CInteger leftObj(left);
	CInteger rightObj(right);
	r.addParameter("left",leftObj);
	r.addParameter("right",rightObj);
	send(r);
}

void CompA::mul()
{
	Request r("Mul");
	CInteger leftObj(left);
	CInteger rightObj(right);
	r.addParameter("left",leftObj);
	r.addParameter("right",rightObj);
	send(r);
}

void CompA::div()
{
	Request r("Div");
	CInteger leftObj(left);
	CInteger rightObj(right);
	r.addParameter("left",leftObj);
	r.addParameter("right",rightObj);
	send(r);
}
