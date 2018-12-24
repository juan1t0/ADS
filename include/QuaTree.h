#include <iostream>
#include <vector>
#include <utility>
#include <windows.h>
#include<GL/glut.h>

using namespace std;

#pragma once
class QuaTree
{
public:
	QuaTree *hijos[4];
	int top;
	int xmin, ymin, Xmax, Ymax;
	bool root;
	bool savePts;
	char nombre = 'a';
	vector<pair<float,float> > puntos;
	void partir();
	bool find(pair<float, float>, QuaTree*&);
	short cuadrante(pair<float, float> &);
//public:
	QuaTree();
	QuaTree(int, int, int,int, int);
	void insert(pair<float, float>&);
	void printQT();
    void draw();

	~QuaTree();
};

