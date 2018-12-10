#include <math.h>
#include <algorithm>
#include <vector>

typedef std::vector<double> dato;
typedef std::size_t tam;

#pragma once
class distance
{
public:
	distance();
	~distance();

	double operator()(dato&, dato&);
};

bool operator ==(dato&, dato&);
bool compararDatos(dato&, dato&);