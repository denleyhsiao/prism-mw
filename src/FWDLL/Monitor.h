// Monitor.h: interface for the Monitor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONITOR_H__3F80CA35_0128_40F1_8B52_B47A3910EB6F__INCLUDED_)
#define AFX_MONITOR_H__3F80CA35_0128_40F1_8B52_B47A3910EB6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ArchitectureEvent.h"

class AFX_EXT_CLASS Monitor  
{
public:
	Monitor();
	virtual ~Monitor();
	Monitor(Monitor &adr);
	Monitor& operator=(Monitor& rhs);

	virtual void see(ArchitectureEvent* evt) = 0; 
};

#endif // !defined(AFX_MONITOR_H__3F80CA35_0128_40F1_8B52_B47A3910EB6F__INCLUDED_)
