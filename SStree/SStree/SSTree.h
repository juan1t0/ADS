#include "SSLeaf.h"
#include "SSBranch.h"

typedef std::vector<SSElement*> nodos;

#pragma once
class SSTree
{
public:
	SSElement* root;
	SSTree();
	~SSTree();
	distance dist;

	bool insert(dato&);
	data search(dato& , uin);
	SSElement* nearSon(SSElement* &, dato&);
	void TreatOverflow(SSElement*&);
	void SplitMaster(SSElement*&);
	void Reinsert(SSElement*& SSN);
	bool remove(SSLeaf*&, uin i);
};

