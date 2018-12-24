#include "classX.h"

classX::classX(){}
classX::~classX(){}
classX::classX(int x,int y,int r){
    centroX = x;
    centroY=y;
    radio=r;
}
void classX::evaluateArea(Nodo*& area){
    Nodo* A;
    if (area->knowIsParent()){
        int c = area->getCantidad();
        for(short i = 0; i < c; ++i){
            search(A = area->getChild(i));
        }
    }
}
void classX::evaluatePoints(Nodo*& area){
    int sis = area->getCantidad();
    float auX, auY;
    for(size_t i =0 ; i<sis;++i){
        auX = area->getPoint(i).first;
        auY = area->getPoint(i).second;
    /*    if (auX>=300)
            auX-=300;
        else
            auX =(300-auX)*-1;
        if (auY<=300)
            auY=300-auY;
        else
            auY=(auY-300)*-1;*/

        if ( (pow(auX-centroX,2)+(pow(auY-centroY,2))) < pow(radio,2)){
            int tx=auX , ty = auY;
            pair<int ,int> temp (tx,ty);
            puntos.push_back(temp);
        }
    }
}

void classX::search(Nodo*& area){
    if (area->knowIsLeaf()){
        evaluatePoints(area);
        return;
    }
    if(allin(area))
        evaluatedAll(area);

    bool dentro = in(area);
    bool seToca = inte(area);
    Nodo* A;
    if (dentro || seToca){
        if(area->knowIsParent()){
            int c = area->getCantidad();
            for(int i = 0 ; i < c; ++i)
                search(A = area->getChild(i));
        }
    }
    return;
}
bool classX::determinante(int val, char eje){
    double D , b2 , otro;
    if(eje == 'x'){
    /*    if (val>=300)
            val-=300;
        else
            val =(300-val)*-1;*/
        otro = 4*((pow(centroX,2)+pow(centroY,2)-pow(radio,2)+pow(val,2)-(2*centroX*val)));
        b2 = pow(-2*centroY,2);
        D = b2 - otro;
    }
    if(eje == 'y'){
    /*    if (val<=300)
            val=300-val;
        else
            val=(val-300)*-1;
*/
        otro = 4*((pow(centroX,2)+pow(centroY,2)-pow(radio,2)+pow(val,2)-(2*centroY*val)));
        b2 = pow(-2*centroX,2);
        D = b2 - otro;
    }
    if (D >= 0)
        return true;
    return false;
}
bool classX::inte(Nodo*& area){
    par_int l = area->getLimite(0), L = area->getLimite(1);
    int auX = L.first;
    int aux = l.first;
    int auY = L.second;
    int auy = l.second;

    bool inTop = determinante(auy,'y');
    bool inBot = determinante(auY,'y');
    bool inLef = determinante(aux,'x');
    bool inRig = determinante(auX,'x');
    bool interseccion = (inTop || inBot || inLef || inRig );
//    cout<<"intersecta _ "<<interseccion<<endl;
    return interseccion;
}

bool classX::in(Nodo*& area){/// problem
    par_int l = area->getLimite(0), L = area->getLimite(1);
    int X = L.first;
    int x = l.first;
    int Y = L.second;
    int y = l.second;
/*
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
*/
    //cout<<"nnn "<<centroX<<" "<<centroY<<" : "<<x<<","<<y<<"|"<<X<<","<<Y<<endl;
    if((centroX < X) && (centroX > x)){
        if((centroY < Y) && (centroY > y)){
//            cout<<"dentro"<<endl;
            return true;
        }
    }
    return false;
}

bool classX::allin(Nodo*& area){
    float auX, auY, aux, auy;
    par_int l = area->getLimite(0), L = area->getLimite(1);
    auX = L.first;
    aux = l.first;
    auY = L.second;
    auy = l.second;
/*    if (auX>=300)
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
*/
    if ((pow(auX-centroX,2)+(pow(auY-centroY,2)))< pow(radio,2)){
       if ((pow(aux-centroX,2)+(pow(auy-centroY,2)))< pow(radio,2)){
            cout<<"esta dentro"<<endl;
            return true;
        }
    }
    return false;

}
void classX::evaluatedAll(Nodo*& area){
    Nodo* A;
    if(area->knowIsParent()){
        int sa = area->getCantidad();
        for(size_t i=0;i<sa;++i){
            evaluatedAll(A = area->getChild(i));
        }
    }else if(area->knowIsLeaf()){
        evaluatePoints(area);
    }
}
