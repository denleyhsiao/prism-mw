// Architecture.cpp: implementation of the Architecture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "Architecture.h"
#include "Component.h"
#include "Connector.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif




//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC( Architecture, Brick )

Architecture::Architecture() {
	components = new CObList(5);
	name = "Prism Architecture";
}

Architecture::Architecture(CString str) {
	name = str;
	components = new CObList(10);
}

Architecture::~Architecture() {
	if(components != NULL) 
		delete components;
}

Architecture::Architecture(Architecture &adr) {
	components = new CObList(adr.components->GetCount());
	POSITION pos;
	for( pos = adr.components->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)components->GetNext( pos );
		components->AddTail(b);
	}
}

Architecture& Architecture::operator=(Architecture& rhs) {
	if(components != NULL) 
		delete components;
	components = new CObList(rhs.components->GetCount());
	POSITION pos;
	for( pos = rhs.components->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)components->GetNext( pos );
		components->AddTail(b);
	}
	return *this;
}

void Architecture::start() {
	POSITION pos;
	for( pos = components->GetHeadPosition(); pos != NULL; )
	{
		Brick* b=(Brick*)components->GetNext( pos );
//		try {
			b->start();
//		} catch (...) {
//			cout << "Error starting the component " << (LPCTSTR)(*b) << "\n";
//		}
	}
}

void Architecture::add(Brick* b) {
	components->AddTail(b);
}

void Architecture::weld(Brick* b1, Brick* b2) {
	if (b1->IsKindOf(RUNTIME_CLASS(Connector))) {
		((Connector*)b1)->addToBottom(b2);
	}
	else {
		((Component*)b1)->setBottom((Connector*)b2);
	}

	if (b2->IsKindOf(RUNTIME_CLASS(Connector))) {
		((Connector*)b2)->addToTop(b1);
	}
	else {
		((Component*)b2)->setTop((Connector*) b1);
	}
}

void Architecture::unweld(Brick* b1, Brick* b2) {
	if (b1->IsKindOf(RUNTIME_CLASS(Connector))) {
		((Connector*)b1)->removeFromBottom(b2);
	} 
	else {
		((Component*)b1)->setBottomFree();
	}

	if (b2->IsKindOf(RUNTIME_CLASS(Connector))) {
		((Connector*)b2)->removeFromTop(b1);
	} 
	else {
		((Component*)b2)->setTopFree();
	}
}

void Architecture::peerWeld(Brick* b1, Brick* b2) {
	if (b1->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
		((PeerConnector*)b1)->addToSide(b2);
	}
	else {
		((Component*)b1)->setSide((PeerConnector*)b2);
	}

	if (b2->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
		((PeerConnector*)b2)->addToSide(b1);
	} else {                                            
		((Component*)b2)->setSide((PeerConnector*)b1);
	}
}

void Architecture::peerUnweld(Brick* b1, Brick* b2) {
	if (b1->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
		((PeerConnector*)b1)->removeFromSide(b2);
	} 
	else {                                            
		((Component*)b1)->setSideFree();
	}

	if (b2->IsKindOf(RUNTIME_CLASS(PeerConnector))) {
		((PeerConnector*)b2)->removeFromSide(b1);
	} else {                                            
		((Component*)b2)->setSideFree();
	}
}

void Architecture::remove(Brick* b) {
	POSITION pos = components->Find(b);
	if(pos != NULL) components->RemoveAt(pos);
}

Brick* Architecture::getReference(CString componentName) {
	POSITION pos;
	for( pos = components->GetHeadPosition(); pos != NULL; ) {
		Brick* b = (Brick*)components->GetNext( pos );
//		cout << "Comparing against " << b->name << "\n";
		if(b->name == componentName)
			return b;
	}
    return NULL;
}

void Architecture::handle(Message& r) {
}

Architecture::operator char*() {
	static char buff[1024];
	strcpy(buff,"Architecture: ");
	strcat(buff,(char *)((LPCTSTR)name));
	strcat(buff,"\n");
	POSITION pos;
	for( pos = components->GetHeadPosition(); pos != NULL; ) {
		Brick* b=(Brick*)components->GetNext( pos );
		strcat(buff,"\t");
		strcat(buff,(char *)b);
	}	
	return buff;
}
