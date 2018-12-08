#include <math.h>
#include <vector>

typedef std::vector<double> dato;
#pragma once
class distance
{
public:
	distance();
	~distance();

	double operator()(dato) {}
};

