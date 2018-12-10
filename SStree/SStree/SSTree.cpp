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
SSElement* SSTree::nearSon(SSElement* &SSN, dato& ssN){
	SSBranch* SSNe = dynamic_cast<SSBranch*>(SSN);
	uin ss = SSNe->quant_child;
	real min_dis = dist(SSNe->children[0]->centroid,ssN); //inicializar distancia
	uin min_son = 0;
	for (uin i = 1; i < ss;++i) {
		real temp_dis = dist(SSNe->children[i]->centroid, ssN);
		if (min_dis > temp_dis) {
			min_dis = temp_dis;
			min_son = i;
		}
	}
	SSElement* N = SSNe->children[min_son];
	return N;
}

void SSTree::TreatOverflow(SSElement* &SSN){
	if (SSN->wasReinsert)
		SplitMaster(SSN);
	else
		Reinsert(SSN);
}
void SSTree::SplitMaster(SSElement*& SSN){
	
	do {
		
		//partir y check padre
	} while ( /*padre tiene overlap*/);
}

void SSTree::Reinsert(SSElement*& SSN) {
	SSN->wasReinsert = true;
	SSLeaf* SSL = dynamic_cast<SSLeaf*>(SSN);
	uin porcent = SSL->M * 0.3;
	data toRe(porcent);
	for (uin i = porcent,j=0; i > 0; --i) {
		toRe[j]= SSL->datos[i];
		remove(SSL,i);
		insert(toRe[j]);
		++j;
	}
}

data SSTree::search(dato& N, uin kn){
	data res(kn);

	return res;
}
bool SSTree::remove(SSLeaf*& SSL,uin i){
	dato dat = SSL->datos[i];
	SSL->datos.erase(SSL->datos.begin()+i);
	while (SSL->parent != 0) {
		//ajustar al mismo
		//cambiar por el padre
	}
	return true;
}