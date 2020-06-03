#ifndef __SYNCHRONIZATION_H_
#define __SYNCHRONIZATION_H_

#include "Afxmt.h"

// The following are the macros for the synchronization of the methods
#define DECLARE_STATIC_SYNCHRONIZED() \
	private: \
		static CCriticalSection staticSynchronizationObject; \


#define IMPLEMENT_STATIC_SYNCHRONIZED(Classname) \
	CCriticalSection Classname::staticSynchronizationObject; \


#define ENTER_STATIC_SYNCHRONIZED() \
	CSingleLock	singleLock(&staticSynchronizationObject); \
	singleLock.Lock(); \
	if(singleLock.IsLocked()) { \


#define LEAVE_STATIC_SYNCHRONIZED() \
	singleLock.Unlock(); \
	} \


#define DECLARE_SYNCHRONIZED() \
	private: \
		CCriticalSection synchronizationObject; \


#define IMPLEMENT_SYNCHRONIZED(Classname) \
	

#define ENTER_SYNCHRONIZED() \
	CSingleLock	singleLock(&synchronizationObject); \
	singleLock.Lock(); \
	if(singleLock.IsLocked()) { \


#define LEAVE_SYNCHRONIZED() \
	singleLock.Unlock(); \
	} \


#define DECLARE_WAIT_NOTIFY() \
	private: \
		CEvent	waitNotifyEvent; \


#define WAIT() \
	{ \
	singleLock.Unlock(); \
	waitNotifyEvent.Lock(); \
	singleLock.Lock(); \
	} \


#define NOTIFY() \
	{ \
	waitNotifyEvent.SetEvent(); \
	} \


#endif