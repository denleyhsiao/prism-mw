// ArchitectureEvent.h: interface for the ArchitectureEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARCHITECTUREEVENT_H__12860198_BF1C_4905_AABE_C3839B8E4C91__INCLUDED_)
#define AFX_ARCHITECTUREEVENT_H__12860198_BF1C_4905_AABE_C3839B8E4C91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Synchronization.h"
#include "EventObject.h"
#include "Address.h"

#define ARCHEVENT_NAMES_REQSENT			"requestSent"
#define ARCHEVENT_NAMES_NOTIFSENT		"notificationSent"
#define ARCHEVENT_NAMES_REQBEINGHDLD	"requestBeingHandled"
#define ARCHEVENT_NAMES_NOTIFBEINGHDLD	"notificationBeingHandled"
#define ARCHEVENT_NAMES_REQHDLD			"requestHandled"
#define ARCHEVENT_NAMES_NOTIFHDLD		"notificationHandled"
#define ARCHEVENT_NAMES_REQRECD			"requestReceived"
#define ARCHEVENT_NAMES_NOTIFRECD		"notificationReceived"
#define ARCHEVENT_NAMES_PEERSENT		"peerSent"
#define ARCHEVENT_NAMES_PEERBEINGHDLD	"peerBeingHandled"
#define ARCHEVENT_NAMES_PEERHDLD		"peerHandled"
#define ARCHEVENT_NAMES_PEERRECD		"peerReceived"

class ArchitectureEvent : public EventObject  
{
	DECLARE_STATIC_SYNCHRONIZED()
public:
	long id;
    CString name;
    CObject** eventDescriptors;
	int descriptorCount;

public:
	ArchitectureEvent();
	virtual ~ArchitectureEvent();
    ArchitectureEvent(Address* source, CString name);
    ArchitectureEvent(Address* source, CString name, int descriptorCount);
	ArchitectureEvent(ArchitectureEvent &adr);
	ArchitectureEvent& operator=(ArchitectureEvent& rhs);

	static long getNextId();
    CObject** getEventDescriptors();
    void addEventDescriptor(int index, CObject* descriptor);
    CObject* getEventDescriptor(int index);
};

#endif // !defined(AFX_ARCHITECTUREEVENT_H__12860198_BF1C_4905_AABE_C3839B8E4C91__INCLUDED_)
