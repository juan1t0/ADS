#include "distance.h"

distance::distance()
{
}
distance::~distance()
{
}

double distance::operator()(dato& A, dato& B) {
	double sum = 0.0;
	tam sa = A.size();
	for (tam i = 0; i < sa; ++i) {
		double aux = abs(A[i]) - abs(B[i]);
		sum += pow(aux, 2);
	}
	return sqrt(sum);
}

bool operator ==(dato& A, dato& B) {
	tam sa = A.size();
	tam sb = B.size();
	if (sa != sb)return false;
	for (tam i = 0; i < sa; ++i) {
		if (A[i] != B[i])return false;
	}
	return true;
}
