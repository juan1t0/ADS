#pragma once
#include "SSElement.h"

typedef std::vector<dato> data;
class SSLeaf :
	public SSElement
{
public:
	data datos;
	uin quant_dato;

	SSLeaf();
	~SSLeaf();

	void sort();
	bool addDato(dato&);
};