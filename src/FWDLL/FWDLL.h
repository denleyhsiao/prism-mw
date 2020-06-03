#ifndef DEF_FWDLL
#define DEF_FWDLL


#ifdef _DEBUG
#pragma comment(lib, "Z:\\Embedded Systems\\Prism\\EVC++\\FWDLL\\X86EMDbg\\FWDLL.lib")
#else
#pragma comment(lib, "Z:\\Embedded Systems\\Prism\\EVC++\\FWDLL\\X86EMRel\\FWDLL.lib")
#endif


#include "Component.h"
#include "Connector.h"
#include "ArchitectureAdapter.h"
#include "FIFODispatch.h"
#include "RoundRobinScheduler.h"
#include "BottomBorderConnector.h"
#include "TopBorderConnector.h"

#endif