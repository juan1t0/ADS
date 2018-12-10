#include "SSBranch.h"



SSBranch::SSBranch()
{
}
SSBranch::~SSBranch()
{
}
void SSBranch::includin(dato& N){
	real d = dist(N, this->centroid);
	if (this->radius >= d) {
		++this->total_children_subtree;
	}
	else {
//		real temp = d - this->radius;
		this->radius = (this->radius + d) / 2;
		//recalcular el centro o despejarlo desde la recta y el circulo
	}
}