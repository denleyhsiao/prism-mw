// ArchitectureAdapter.cpp: implementation of the ArchitectureAdapter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ArchitectureAdapter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ArchitectureAdapter::ArchitectureAdapter()
{
}

ArchitectureAdapter::~ArchitectureAdapter()
{
}

ArchitectureAdapter::ArchitectureAdapter(CString name) : Architecture(name)
{
}
	
ArchitectureAdapter::ArchitectureAdapter(ArchitectureAdapter &adr) {
}

ArchitectureAdapter& ArchitectureAdapter::operator=(ArchitectureAdapter& rhs) {
	return *this;
}

bool ArchitectureAdapter::hasTop() {
	return false;
}

bool ArchitectureAdapter::hasBottom() {
	return false;
}

bool ArchitectureAdapter::hasSide() {
	return false;
}

CObject* ArchitectureAdapter::getTop() {
	return NULL;
}

CObject* ArchitectureAdapter::getBottom() {
	return NULL;
}

CObject* ArchitectureAdapter::getSide() {
	return NULL;
}

void ArchitectureAdapter::setTop(Connector* conn) {
}

void ArchitectureAdapter::setBottom(Connector* conn) {
}

void ArchitectureAdapter::setSide(PeerConnector* conn) {
}

void ArchitectureAdapter::addToTop(Brick* top) {
}

void ArchitectureAdapter::addToBottom(Brick* bottom) {
}

void ArchitectureAdapter::addToSide(Brick* side) {
}

void ArchitectureAdapter::removeFromTop(Brick* top) {
}

void ArchitectureAdapter::removeFromBottom(Brick* bottom) {
}

void ArchitectureAdapter::removeFromSide(Brick* side) {
}

void ArchitectureAdapter::send(Request* r) {
}

void ArchitectureAdapter::send(Notification* n) {
}

void ArchitectureAdapter::send(Peer* p) {
}
