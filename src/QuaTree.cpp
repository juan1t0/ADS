#include "QuaTree.h"

QuaTree::QuaTree(){}
QuaTree::QuaTree(int x,int y, int X, int Y, int t)
{
	this->xmin = x;
	this->ymin = y;
	this->Xmax = X;
	this->Ymax = Y;
	this->top = t;
	this->root = false;
	this->savePts = true;
}
QuaTree::~QuaTree(){}

short QuaTree::cuadrante(pair<float, float> &a){
	float x = a.first, y = a.second;
	int ejeX = (Xmax + xmin) / 2, ejeY = (Ymax + ymin) / 2;
	if (x > ejeX) {
		if (y > ejeY)
			return 3;
		else
			return 0;
	}
	else {
		if (y > ejeY)
			return 2;
		else
			return 1;
	}
}

bool QuaTree::find(pair<float, float> ptx, QuaTree *&qt)
{
	while (qt->root) {
		short c = qt->cuadrante(ptx);
		qt = qt->hijos[c];
	}
	size_t sis = qt->puntos.size(), i;
	if (sis == 0){
        return false;
	}
	for (i = 0; (i < sis) && (qt->puntos[i] != ptx); ++i)
		;
	if(qt->puntos[i] == ptx)
		return true;
	return false;
}

void QuaTree::partir() {
	int ejeX = (Xmax + xmin) / 2, ejeY = (Ymax + ymin) / 2;
	vector<pair<float, float> > temp(this->puntos);

	this->root = true;
	this->savePts = false;
	this->puntos.clear();
	this->hijos[0] = new QuaTree(ejeX, this->ymin, this->Xmax, ejeY, this->top);
	this->hijos[1] = new QuaTree(this->xmin, this->ymin, ejeX, ejeY, this->top);
	this->hijos[2] = new QuaTree(this->xmin, ejeY, ejeX, this->Ymax, this->top);
	this->hijos[3] = new QuaTree(ejeX, ejeY, this->Xmax, this->Ymax, this->top);

	size_t sis = temp.size();
	for (size_t i = 0; i < sis; ++i) {
		short c = this->cuadrante(temp[i]);
		this->hijos[c]->puntos.push_back(temp[i]);
		this->hijos[c]->savePts = (this->hijos[c]->puntos.size() < this->hijos[c]->top);
	}
}
void QuaTree::insert(pair<float, float> &ptx) {
	QuaTree *qt = this;
	bool f = find(ptx, qt);
	if (!f) {
		if (qt->savePts) {
			qt->puntos.push_back(ptx);
			qt->savePts = (qt->puntos.size() < qt->top);
			return;
		}
		else{
		    qt->partir();
            short c = qt->cuadrante(ptx);
            qt->hijos[c]->insert(ptx);
		}
	}
	else {
		//cout << "punto repetido \n";
	}
}
void QuaTree::printQT() {
	cout << ": ";
	if (this == 0) return;
	size_t s = this->puntos.size();
	for (short i = 0; i < s; ++i) {
		cout << puntos[i].first << " " << puntos[i].second << " , ";
	}
	for (short i = 0; i < 4; ++i) {
		cout << "\n";
		hijos[i]->printQT();
	}
}

void QuaTree::draw(){
    if (this->root){
        int xl=this->Xmax - this->xmin;

        float m1 = xl/2;
        float c1 = xmin+m1,c2=ymin+m1;

        if (c1>=300)
            c1-=300;
        else
            c1 =(300-c1)*-1;
        if (c2<=300)
            c2=300-c2;
        else
            c2=(c2-300)*-1;

        glBegin(GL_LINES);
            glColor3f(0.0f,0.0f,0.0f);
            glVertex2d(c1+m1, c2);///()
            glVertex2d(c1-m1, c2);///()
            glColor3f(0.0f,0.0f,0.0f);
            glVertex2d(c1, c2+m1);///()
            glVertex2d(c1, c2-m1);///()
        glEnd();

        this->hijos[0]->draw();
        this->hijos[1]->draw();
        this->hijos[2]->draw();
        this->hijos[3]->draw();
   }
}
