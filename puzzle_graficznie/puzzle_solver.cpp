#include "puzzle_solver.h"
#include <iostream>
#include <math.h>
#include "PQ_lista.h"


using namespace std;

//////////////////////////////astar/////////////////////////////////

astar::astar(int **tablica,int N,astar *rodzic){
    size=N;
    parent=rodzic;
    next=NULL;
    tab = new int *[N];
    for(int i=0;i<N;i++){
        tab[i] = new int [N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tab[i][j]=tablica[i][j];
            if(tab[i][j]==0){x=i;y=j;}
        }
    }
}

astar::~astar(){
    for(int i=0;i<size;i++){
        delete []tab[i];
    }
    delete []tab;
    delete next;
}


bool astar::check_left(){

    if(parent==NULL){if(y>0)return 1;}
    else{
        if(y>0 and parent->y - y!=-1)return 1;}
    return 0;
}
bool astar::check_right(){

    if(parent==NULL){if(y<size-1)return 1;}
    else{
        if(y<size-1 and parent->y - y!=1)return 1;}
    return 0;
}
bool astar::check_up(){

    if(parent==NULL){if(x>0)return 1;}
    else{
        if(x>0 and parent->x - x!=-1)return 1;}
    return 0;
}
bool astar::check_down(){

    if(parent==NULL){if(x<size-1)return 1;}
    else{
        if(x<size-1 and parent->x - x!=1)return 1;}
    return 0;
}

void astar::left_tab(){

    int pom=tab[x][y];
    tab[x][y]=tab[x][y-1];
    tab[x][y-1]=pom;
    y--;
}
void astar::right_tab(){

    int pom=tab[x][y];
    tab[x][y]=tab[x][y+1];
    tab[x][y+1]=pom;
    y++;
}
void astar::up_tab(){

    int pom=tab[x][y];
    tab[x][y]=tab[x-1][y];
    tab[x-1][y]=pom;
    x--;
}
void astar::down_tab(){

    int pom=tab[x][y];
    tab[x][y]=tab[x+1][y];
    tab[x+1][y]=pom;
    x++;
}

void astar::manhattan(int **goal){
    int wynik=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                for(int l=0;l<size;l++){
                    if(tab[i][j]==goal[k][l] and tab[i][j]!=0 and goal[k][l]!=0 ){
                        wynik+=abs(i-k)+abs(j-l);
                    }
                }
            }
        }
    }

    h= wynik;

}
bool astar::compare_tab(astar *goal){
    if(h!=goal->h)return false;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab[i][j]!=goal->tab[i][j]){return false;}

        }
    }
    return true;
}

///////////////////////////////AS///////////////////////////////////
AS::AS(int **tablica,int **tablica_goal,int N){
    size=N;
    podpowiedz=NULL;

    tab = new int *[N];
    goal = new int *[N];
    for(int i=0;i<N;i++){
        tab[i] = new int [N];
        goal[i] = new int [N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tab[i][j]=tablica[i][j];
            goal[i][j]=tablica_goal[i][j];
        }
    }
}

AS::~AS(){
    for(int i=0;i<size;i++){
        delete []tab[i];
        delete []goal[i];
    }
    delete []tab;
    delete []goal;

    delete podpowiedz;

}

void AS::solve(){

    PQ_lista open;
    astar ******hash_list=make_hash();


    astar *first=new astar(tab,size);
    first->g=0;
    first->manhattan(goal);
    first->f=first->g+first->h;
    open.insert(first,first->f);
    add_hash(first,hash_list);


    astar *X;
    astar *d1=NULL,*d2=NULL,*d3=NULL,*d4=NULL;



    while(open.min()!=NULL){

        X=open.extract_min();

        if(X->h==0){ break;}

        if(X->check_left()){
            d1=new astar(X->tab,size,X);

            d1->left_tab();
            d1->g=X->g+1;
            d1->manhattan(goal);
            d1->f=d1->g+d1->h;
            bool o1=child(d1,hash_list);
            if(o1){open.insert(d1,d1->f);
                add_hash(d1,hash_list);
            }

        }
        if(X->check_right()){
            d2=new astar(X->tab,size,X);
            d2->right_tab();
            d2->g=X->g+1;
            d2->manhattan(goal);
            d2->f=d2->g+d2->h;
            bool o2=child(d2,hash_list);

            if(o2){open.insert(d2,d2->f);
                add_hash(d2,hash_list);
            }
        }
        if(X->check_up()){
            d3=new astar(X->tab,size,X);
            d3->up_tab();
            d3->g=X->g+1;
            d3->manhattan(goal);
            d3->f=d3->g+d3->h;
            bool o3=child(d3,hash_list);

            if(o3){open.insert(d3,d3->f);
                add_hash(d3,hash_list);

            }
        }
        if(X->check_down()){
            d4=new astar(X->tab,size,X);
            d4->down_tab();
            d4->g=X->g+1;
            d4->manhattan(goal);
            d4->f=d4->g+d4->h;
            bool o4=child(d4,hash_list);
            if(o4){open.insert(d4,d4->f);
                add_hash(d4,hash_list);
            }

        }


    }

    zwracanie_wyniku(X);
    open.usun();

    delete_hash(hash_list);



}

bool AS::child(astar *&d, astar ******hash_list){
    if(!exist_hash(d,hash_list)){
        return true;
    }else{
        delete d;
        return false;
    }

}
void AS::zwracanie_wyniku(astar *X){
    astar *wynik=NULL;
    astar *pom=NULL;
    while(X!=NULL){
        pom=new astar(X->tab,size,NULL);
        pom->next=wynik;
        wynik=pom;
        X=X->parent;
    }
    pom=NULL;delete pom;
    podpowiedz=wynik;

}
bool AS::compare(int **tab2,int **tab1){

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab1[i][j]!=tab2[i][j]){return false;}

        }
    }
    return true;
}

int AS::hint(){
    if(podpowiedz==NULL)return 5;
    if(podpowiedz->next==NULL)return 5;
    int xp=podpowiedz->next->x,yp=podpowiedz->next->y;
    int x=podpowiedz->x,y=podpowiedz->y;
    if(yp-y==-1){return 0;}
    if(yp-y==1){return 1;}
    if(xp-x==-1){return 2;}
    if(xp-x==1){return 3;}

return 5;
}
void AS::status(int **X){
    if(!compare(X,tab)){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                tab[i][j]=X[i][j];

            }
        }
    }
    if(podpowiedz==NULL){solve();}else{
        if(!compare(X,podpowiedz->tab))
        {if(podpowiedz->next==NULL){
                astar*pom=podpowiedz;
                podpowiedz=NULL;
                delete pom;
                solve();
            }else{
                if(compare(X,podpowiedz->next->tab)){
                    astar*pom=podpowiedz;
                    podpowiedz=podpowiedz->next;
                    pom->next=NULL;
                    delete pom;

                }else{
                    astar*pom=podpowiedz;
                    podpowiedz=NULL;
                    delete pom;
                    solve();}
            }

        }

    }

}


/////////////////////hash list///////////////////////////

astar ******AS::make_hash(){
    astar****** tab=new astar*****[((size+size)-1)*((size*size)-1)];
    for(int i=0;i<((size+size)-1)*((size*size)-1);i++){
        tab[i]=new astar****[size];
        for(int j=0;j<size;j++){
            tab[i][j]=new astar***[size];
            for(int k=0;k<size;k++){
                tab[i][j][k]=new astar**[size*size];
                for(int l=0;l<size*size;l++){
                    tab[i][j][k][l]=new astar *[size*size];
                }
            }

        }
    }
    for(int i=0;i<((size+size)-1)*((size*size)-1);i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                for(int l=0;l<size*size;l++){
                    for(int m=0;m<size*size;m++){

                        tab[i][j][k][l][m]=NULL;
                    }

                }
            }
        }
    }

    return tab;
}


void AS::delete_hash(astar ******&tab){



    for(int i=0;i<((size+size)-1)*((size*size)-1);i++){

        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                for(int l=0;l<size*size;l++){
                    for(int m=0;m<size*size;m++){
                        delete tab[i][j][k][l][m];
                    }
                    delete []tab[i][j][k][l];
                }
                delete [] tab[i][j][k];
            }
            delete [] tab[i][j];

        }
        delete []tab[i];
    }
    delete []tab;
}


void AS::add_hash(astar *X,astar ******&tab){
    int i=X->h;
    int j=X->x;
    int k=X->y;
    int l=X->tab[0][0];
    int m=X->tab[size-1][size-1];

    if(tab[i][j][k][l][m]==NULL){
        tab[i][j][k][l][m]=X;
    }else{
        X->next=tab[i][j][k][l][m];
        tab[i][j][k][l][m]=X;
    }

}


bool AS::exist_hash(astar *X,astar ******&tab){
    int i=X->h;
    int j=X->x;
    int k=X->y;
    int l=X->tab[0][0];
    int m=X->tab[size-1][size-1];
    if(tab[i][j][k][l][m]==NULL){return false;}
    astar *pom=tab[i][j][k][l][m];
    while(pom!=NULL){
        if(pom->compare_tab(X)){return true;}
        pom=pom->next;
    }
    return false;
}


























