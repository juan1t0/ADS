#include "classX.h"

classX::classX(){}
classX::~classX(){}
classX::classX(int x,int y,int r){
    centroX = x;
    centroY=y;
    radio=r;
}
void classX::evaluateArea(QuaTree*& area){
    if (area->root){
        for(short i=0;i<4;++i){
            search(area->hijos[i]);
        }
    }
}
void classX::evaluatePoints(QuaTree*& area){
    size_t sis = area->puntos.size();
    float auX, auY;
    for(size_t i =0 ; i<sis;++i){
        auX = area->puntos[i].first;
        auY = area->puntos[i].second;
        if (auX>=300)
            auX-=300;
        else
            auX =(300-auX)*-1;
        if (auY<=300)
            auY=300-auY;
        else
            auY=(auY-300)*-1;

        if ( (pow(auX-centroX,2)+(pow(auY-centroY,2)))< pow(radio,2)){
            int tx=auX , ty = auY;
            pair<int ,int> temp (tx,ty);
            puntos.push_back(temp);
        }
    }
}

void classX::search(QuaTree*& area){
    bool isHoja = (area->puntos.size() > 0);
    if (isHoja){
        evaluatePoints(area);
        return;
    }
    if(allin(area)){
        evaluatedAll(area);
    }
    bool dentro = in(area);
    bool seToca = inte(area);
    if (dentro || seToca){
        if(area->root){
            for(short i=0;i<4;++i)
                search(area->hijos[i]);
        }
    }
    return;
}
bool classX::determinante(int val, char eje){
    double D , b2 , otro;
    if(eje == 'x'){
        if (val>=300)
            val-=300;
        else
            val =(300-val)*-1;
        otro = 4*((pow(centroX,2)+pow(centroY,2)-pow(radio,2)+pow(val,2)-(2*centroX*val)));
        b2 = pow(-2*centroY,2);
        D = b2 - otro;
    }
    if(eje == 'y'){
        if (val<=300)
            val=300-val;
        else
            val=(val-300)*-1;

        otro = 4*((pow(centroX,2)+pow(centroY,2)-pow(radio,2)+pow(val,2)-(2*centroY*val)));
        b2 = pow(-2*centroX,2);
        D = b2 - otro;
    }
    if (D >= 0)
        return true;
    return false;
}
bool classX::inte(QuaTree*& area){
    bool inTop = determinante(area->ymin,'y');
    bool inBot = determinante(area->Ymax,'y');
    bool inLef = determinante(area->xmin,'x');
    bool inRig = determinante(area->Xmax,'x');
    bool interseccion = inTop || inBot || inLef || inRig ;
    return interseccion;
}

bool classX::in(QuaTree*& area){
    int x=area->xmin , y=area->ymin;
    int X=area->Xmax , Y=area->Ymax;

    if (x>=300)
        x-=300;
    else
        x =(300-x)*-1;
    if (y<=300)
        y=300-y;
    else
        y=(y-300)*-1;
    if (X>=300)
        X-=300;
    else
        X =(300-X)*-1;
    if (Y<=300)
        Y=300-Y;
    else
        Y=(Y-300)*-1;

    if((centroX < X) && (centroX > x)){
        if((centroY > Y) && (centroY < y)){
            return true;
        }
    }
    return false;
}

bool classX::allin(QuaTree*& area){
    float auX, auY, aux, auy;
    auX = area->Xmax;
    aux = area->xmin;
    auY = area->Ymax;
    auy = area->ymin;
    if (auX>=300)
        auX-=300;
    else
        auX =(300-auX)*-1;
    if (auY<=300)
        auY=300-auY;
    else
        auY=(auY-300)*-1;
    if (aux>=300)
        aux-=300;
    else
        aux =(300-aux)*-1;
    if (auy<=300)
        auy=300-auy;
    else
        auy=(auy-300)*-1;

    if ((pow(auX-centroX,2)+(pow(auY-centroY,2)))< pow(radio,2)){
       if ((pow(aux-centroX,2)+(pow(auy-centroY,2)))< pow(radio,2)){
            return true;
        }
    }
    return false;

}
void classX::evaluatedAll(QuaTree*& area){
    if(area->root){
        evaluatedAll(area->hijos[0]);
        evaluatedAll(area->hijos[1]);
        evaluatedAll(area->hijos[2]);
        evaluatedAll(area->hijos[3]);
    }else if(area->savePts){
        size_t sa = area->puntos.size();
        for(size_t i=0;i<sa;++i){
            puntos.push_back(area->puntos[i]);
        }
    }
}
