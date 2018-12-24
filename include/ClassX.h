#ifndef CLASSX_H
#define CLASSX_H

#include "Nodo.h"
#include <vector>
#include <utility>
#include <math.h>

class classX
{
public:
    classX();
    classX(int x,int y, int r);
    virtual ~classX();

    void search(Nodo*& area);
    bool in(Nodo*& area);
    bool inte(Nodo*& area);
    bool determinante (int val,char eje);
    bool allin(Nodo*& area);
    void evaluatedAll(Nodo*& area);
    vector<Nodo*> containers;
    vector<pair<int , int> > puntos;
    int centroX;
    int centroY;
    int radio;

    void evaluateArea(Nodo*& area);
    void evaluatePoints(Nodo*& area);
};

#endif // CLASSX_H
