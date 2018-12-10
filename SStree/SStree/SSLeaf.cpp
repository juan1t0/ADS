#include "SSLeaf.h"



SSLeaf::SSLeaf()
{
}
SSLeaf::~SSLeaf()
{
}

bool SSLeaf::addDato(dato& N) {
	//revisar si se repite, opcional
	//añadirlo a los datos
	this->datos.push_back(N);
	real d = dist(N, this->centroid);
	if (this->radius >= d) {
		++this->quant_dato;
	}
	else {
		//		real temp = d - this->radius;
		this->radius = (this->radius + d) / 2;
		//recalcular el centro o despejarlo desde la recta y el circulo
	}
	return true;
}

void SSLeaf::sort(){
	dato cc = this->centroid;

}