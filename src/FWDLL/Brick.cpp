// Brick.cpp: implementation of the Brick class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Brick.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNAMIC(Brick,CObject)

Brick::Brick()
{
	topId = new Address(-1);
	bottomId = new Address(-1);
	sideId = new Address(-1);
	scaffold = NULL;
}

Brick::~Brick()
{
	// delete(messageFIFO); // Raghbir
	if(topId != NULL)
		delete topId;
	if(bottomId != NULL)
		delete bottomId;
	if(sideId != NULL)
		delete sideId;
}

Brick::Brick(CString n)
{
	topId = new Address(-1);
	bottomId = new Address(-1);
	sideId = new Address(-1);
	scaffold = NULL;
	this->name=n;
}

Brick::Brick(Brick &adr) {
	myId = adr.myId;
	name = adr.name;
	scaffold = adr.scaffold;
	topId = new Address(adr.topId->getNumeric());
	bottomId = new Address(adr.bottomId->getNumeric());
	sideId = new Address(adr.sideId->getNumeric());
}

Brick& Brick::operator=(Brick& rhs) {
	if(topId != NULL)
		delete topId;
	if(bottomId != NULL)
		delete bottomId;
	if(sideId != NULL)
		delete sideId;
	myId = rhs.myId;
	name = rhs.name;
	scaffold = rhs.scaffold;
	topId = new Address(rhs.topId->getNumeric());
	bottomId = new Address(rhs.bottomId->getNumeric());
	sideId = new Address(rhs.sideId->getNumeric());
	return *this;
}

void Brick::handle(Request& r)
{
	//should be overloaded to handle requests
}

void Brick::handle(Notification& n)
{
	//should be overloaded to handle notifications
}

void Brick::handle(Peer& p)
{
	//should be overloaded to handle notifications
}

void Brick::start()
{
	//should be overloaded to handle notifications
}

void Brick::create(CString s)
{
	name=s;
}

void Brick::setScaffold(Scaffold* scaffold) {
	this->scaffold = scaffold;
}

void Brick::setTopId(Address* id) {
	topId = id;
}

Address* Brick::getTopId() {
	return topId;
}

void Brick::setSideId(Address* id) {
	sideId = id;
}

Address* Brick::getSideId() {
	return sideId;
}

void Brick::setBottomId(Address* id) {
	bottomId = id;
}

Address* Brick::getBottomId() {
	return bottomId;
}

void Brick::fireEvent(ArchitectureEvent* event) {
    if (scaffold != NULL && (scaffold->getType() & SCAFFOLD_TYPE_MONITOR) != 0) 
    {
		scaffold->call("see", event);
	}
}

void Brick::add(Message* message) {
    if (scaffold != NULL && (scaffold->getType() & SCAFFOLD_TYPE_DISPATCH) != 0) 
    {
		scaffold->call("add", message);
	}
}

void Brick::setName(CString n) {
	name = n;
}

Brick::operator char*() {
	static char buff[256];
	strcpy(buff,"Brick: ");
	strcat(buff,(char *)(LPCTSTR)name);
	strcat(buff,"\n");
	return buff;
}

