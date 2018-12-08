#include "SSLeaf.h"
#include "SSBranch.h"

#pragma once
class SSTree
{
public:
	SSElement* root;
	SSTree();
	~SSTree();

	bool insert(dato&);
	data search(dato& , uin);
	SSElement* nearSon(SSElement* &, dato&);
	void TreatOverflow(SSElement*&);
	void SplitMaster(SSElement*&);
	void Reinsert(SSElement*& SSN);
};

