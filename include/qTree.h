#ifndef QTREE_H
#define QTREE_H
#include <vector>
#include <utility>
#include <windows.h>
#include <math.h>
#include<GL/glut.h>
#include <iostream>

/**
    hacer un buscador, trabaja con punteros oye
**/

using namespace std;
//template <class C>
class qTree
{
    qTree * areas[4];
    int top;
    bool nil=true, root=false;
    vector<pair<float,float> > *puntos;
    float X,Y; /// x->Xmin=0 y->Ymin=0 | X->Xmax Y->Ymax
    float x,y;
    int get_Qua(pair<float,float> pt);
    bool cont();
public:
    qTree();
    qTree(float X,float Y,int top);
    ~qTree();
    void draw();
  //  C f;
    void insert_pt(pair<float,float> pt);
    void set_x(float x);
    void set_y(float y);
    void set_X(float X);
    void set_Y(float Y);
    void set_top(int t);
};

#endif // QTREE_H
