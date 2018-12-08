#include <vector>
#include "distance.h"
typedef unsigned int uin;
typedef double real;
//typedef std::vector<real> dato;

#pragma once
class SSElement
{
public:
	uin height;
	uin updateCont;
	real radius;
	dato centroid;
	real variance;
	uin M, m;
	SSElement* parent;
	bool isLeaf;
	bool wasReinsert;

	SSElement();
	~SSElement();

	virtual void includin(dato&) {}
	virtual bool addDato(dato&) {}
};

