// FIFODispatch.cpp: implementation of the FIFODispatch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FIFODispatch.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SYNCHRONIZED(FIFODispatch)

FIFODispatch::FIFODispatch()
{
	size = DEFAULT_SIZE;
	queue = new CObject*[size+1];
	head = 0;
	tail = 0;
	emptySlots = size;
}

FIFODispatch::FIFODispatch(int FIFOSize)
{
	size = FIFOSize;
	queue = new CObject*[size+1];
	head = 0;
	tail = 0;
	emptySlots = size;
}

FIFODispatch::~FIFODispatch()
{
	if(queue != NULL)
		delete [] queue;
}

FIFODispatch::FIFODispatch(FIFODispatch &adr) {
    emptySlots = adr.emptySlots;
    head = adr.head;
    size = adr.size;
    tail = adr.tail;
	queue = new CObject*[size+1];
}

FIFODispatch& FIFODispatch::operator=(FIFODispatch& rhs) {
	if(queue != NULL)
		delete [] queue;
    emptySlots = rhs.emptySlots;
    head = rhs.head;
    size = rhs.size;
    tail = rhs.tail;
	queue = new CObject*[size+1];
	for(int i =0; i<=size; i++)
		queue[i] = rhs.queue[i];
	return *this;
}

void FIFODispatch::add(Message* m) {
	ENTER_SYNCHRONIZED()
//	try
//	{
		while (isQueueFull()) {
			WAIT()
		}
//	}
//	catch (...)
//	{
//	}
	queue[tail] = m;
	incrementTail();
	--emptySlots;
	if((emptySlots + 1) == size) {
		NOTIFY()
	}
	LEAVE_SYNCHRONIZED()
}

Message* FIFODispatch::getMessage() {
	Message *m = NULL;
	ENTER_SYNCHRONIZED()
//	try
//	{
		while (isQueueEmpty()) {
			WAIT()
		}
//	}
//	catch (...)
//	{
//	}
	m = (Message*) queue[head];
	queue[head]=NULL;
	incrementHead();
	++emptySlots;
	if(emptySlots == 2) {
		NOTIFY()
	}
	LEAVE_SYNCHRONIZED()
	return m;
}

int FIFODispatch::getWaitingLength() {
	int retval;
	ENTER_SYNCHRONIZED()
    retval = size - emptySlots;
	LEAVE_SYNCHRONIZED()
	return retval;
}

void FIFODispatch::setMessageCapacity(int n) {
}

FIFODispatch::operator char*() {
	static char buffer[512];
	if (head == tail) {
		strcpy(buffer,"Empty");
		return buffer;
	}
	else
		strcpy(buffer,(char*)(LPCTSTR)((Message*) queue[head])->name);
	int start = head + 1;
	if (start > size)
		start = 0;
	for (int i = start; ; i++)
	{
		if (i == tail)
			break;
		strcat(buffer,", ");
		strcat(buffer,(char *)(LPCTSTR)((Message*) queue[i])->name);
		if (i == size)
			i = -1;
	}
	return buffer;
}

bool FIFODispatch::isQueueEmpty() {
	return (emptySlots == size);
}

bool FIFODispatch::isQueueFull() {
	return (emptySlots == 1);
}

void FIFODispatch::incrementTail() {
	if (tail == size - 1)
		tail = 0;
	else
		++tail;
}

void FIFODispatch::incrementHead() {
	if (head == size - 1)
		head = 0;
	else
		++head;
}
