#include "qTree.h"
qTree::qTree(){
    areas[0]=0;
    areas[1]=0;
    areas[2]=0;
    areas[3]=0;
    x=y=0;
    X=Y=1;
    cout<<"creado"<<endl;
}
qTree::qTree(float x,float y,int top){
    areas[0]=0;
    areas[1]=0;
    areas[2]=0;
    areas[3]=0;
    this->X=x;
    this->Y=y;
    this->x=0;
    this->y=0;
    this->top=top;
    puntos = new vector<pair<float,float> >;
}
int qTree::get_Qua(pair<float,float> pt)
{
    float x2 = (X+x)/2, y2 = (Y+y)/2;;
    if( pt.first < x2 ) {
        if(pt.second < y2)
            return 0;
        else
            return 1;
    }
    else{
        if(pt.second < y2)
            return 2;
        else
            return 3;
    }
}
bool qTree::cont(){
    if(root)return false;
    size_t s = puntos->size();
    return (top > s);
}
void qTree::insert_pt(pair<float,float> pt){
    if (nil){
        puntos->push_back(pt);
        nil=cont();
        return;
    }
    else{
        if(!root){
            this->root = true;
            for(short i=0;i<4;i++)
                areas[i]=new qTree();
            {
                areas[0]->set_x(this->x);
                areas[0]->set_y(this->y);
                areas[0]->set_X((this->X)/2);
                areas[0]->set_Y((this->Y)/2);
                areas[0]->set_top(this->top);
                areas[0]->puntos = new vector<pair<float,float> >;
            }
            {
                areas[1]->set_x(this->x);
                areas[1]->set_y(((this->Y)/2)+1);
                areas[1]->set_X(((this->X)/2)+1);
                areas[1]->set_Y(this->Y);
                areas[1]->set_top(this->top);
                areas[1]->puntos = new vector<pair<float,float> >;
            }
            {
                areas[2]->set_x(((this->X)/2)+1);
                areas[2]->set_y(this->y);
                areas[2]->set_X(this->X);
                areas[2]->set_Y(((this->Y)/2)+1);
                areas[2]->set_top(this->top);
                areas[2]->puntos = new vector<pair<float,float> >;
            }
            {
                areas[3]->set_x(((this->X)/2)+1);
                areas[3]->set_y(((this->X)/2)+1);
                areas[3]->set_X(this->X);
                areas[3]->set_Y(this->Y);
                areas[3]->set_top(this->top);
                areas[3]->puntos = new vector<pair<float,float> >;
            }
           // this->insert_pt(pt);
        }
    //    else{
            puntos->push_back(pt);
            size_t sptas = puntos->size();
            cout<<sptas<<" -> pts a borrar"<<endl;
            for(size_t i =0;i<sptas ;i++){
                pair<float,float> pta = puntos->at(0);
                puntos->erase(puntos->begin());
                areas[get_Qua(pta)]->insert_pt(pta);
                cout<< pta.first<<" , "<<pta.second<<" ahora en -> "<< get_Qua(pta)<<endl;
            }
            cout<<puntos->size()<<" -> pts"<<endl;
    //        puntos->clear();
//            areas[get_Qua(pt)]->insert_pt(pt);
            return;
     //   }
    }
}
void qTree::set_x(float x){this->x = x;}
void qTree::set_y(float y){this->y = y;}
void qTree::set_X(float X){this->X = X;}
void qTree::set_Y(float Y){this->Y = Y;}
void qTree::set_top(int t){this->top = t;}

void qTree::draw()
{
    if (root){
        int xl=this->X - this->x;

        float m1 = xl/2;
        float c1 = x+m1,c2=y+m1;

        if (c1>=300)
            c1-=300;
        else
            c1 =(300-c1)*-1;
        if (c2<=300)
            c2=300-c2;
        else
            c2=(c2-300)*-1;

        glBegin(GL_LINES);
            glColor3d(0,0,0);
            glVertex2d(c1+m1, c2);///()
            glVertex2d(c1-m1, c2);///()
            glColor3d(0, 0, 0);
            glVertex2d(c1, c2+m1);///()
            glVertex2d(c1, c2-m1);///()
        glEnd();

        areas[0]->draw();
        areas[1]->draw();
        areas[2]->draw();
        areas[3]->draw();
   }
}
