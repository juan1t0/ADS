#ifndef CLASSX_H
#define CLASSX_H
#include "QuaTree.h"
#include <vector>
#include <utility>
#include <math.h>

class classX
{
public:
    classX();
    classX(int x,int y, int r);
    virtual ~classX();

    void search(QuaTree*& area);
    bool in(QuaTree*& area);
    bool inte(QuaTree*& area);
    bool determinante (int val,char eje);
    bool allin(QuaTree*& area);
    void evaluatedAll(QuaTree*& area);
    vector<QuaTree*> containers;
    vector<pair<int , int> > puntos;
    int centroX;
    int centroY;
    int radio;

    void evaluateArea(QuaTree*& area);
    void evaluatePoints(QuaTree*& area);
};

#endif // CLASSX_H
