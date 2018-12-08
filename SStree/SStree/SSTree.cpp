#include "SSTree.h"

SSTree::SSTree()
{
	root = new SSLeaf;
}
SSTree::~SSTree()
{
}

bool SSTree::insert(dato &ssN){
	SSElement* SSN = this->root;
	while (! SSN->isLeaf) {
		
		SSBranch* aux = dynamic_cast<SSBranch*>(nearSon(SSN,ssN)); // buscamos al hijo que este mas cerca a ssN
		SSN->includin(ssN);//incluimos a ssn, ajustamos el radio y todo lo necesario
		SSN = aux;
	}
	SSLeaf* SSL = dynamic_cast<SSLeaf*>(SSN);
	if (SSL->quant_dato < SSN->M) { //no overflow
		return SSL->addDato(ssN);
	}
	else {
		bool i = SSL->addDato(ssN);
		if (i)TreatOverflow(SSN = SSL);
		return i;
	}
	return false;
}
SSElement* SSTree::nearSon(SSElement* &SSN, dato& ssN){}
void SSTree::TreatOverflow(SSElement* &SSN){
	if (SSN->wasReinsert)
		SplitMaster(SSN);
	else
		Reinsert(SSN);
}
void SSTree::SplitMaster(SSElement*& SSN){}

void SSTree::Reinsert(SSElement*& SSN) {}

data SSTree::search(dato& N, uin kn){

}