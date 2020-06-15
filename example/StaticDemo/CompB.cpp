// CompB.cpp: implementation of the CompB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StaticDemo.h"
#include "CompB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CompB::CompB()
{
	this->name="B";
}

CompB::~CompB()
{

}

void CompB::handle (Request& r)
{
	
	int left;
	int right;
	CInteger* pleft;
	CInteger* pright;
	if (r.name=="Add")
	{
		pleft=(CInteger*)(r.getParameter("left"));
		pright=(CInteger*)(r.getParameter("right"));

		left=pleft->value;
		right=pright->value;
		int rez=left+right;
		Notification n("Result");
		CInteger rezObj(rez);
		n.addParameter("result",rezObj);
		send(n);
	}
	else if (r.name=="Sub")
	{
		pleft=(CInteger*)(r.getParameter("left"));
		pright=(CInteger*)(r.getParameter("right"));

		left=pleft->value;
		right=pright->value;
		int rez=left-right;
		Notification n("Result");
		CInteger rezObj(rez);
		n.addParameter("result",rezObj);
		send(n);
	}
	else	if (r.name=="Mul")
	{
		pleft=(CInteger*)(r.getParameter("left"));
		pright=(CInteger*)(r.getParameter("right"));

		left=pleft->value;
		right=pright->value;
		int rez=left*right;
		Notification n("Result");
		CInteger rezObj(rez);
		n.addParameter("result",rezObj);
		send(n);
	}
}
