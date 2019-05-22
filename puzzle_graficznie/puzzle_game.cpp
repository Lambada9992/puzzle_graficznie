#include "puzzle_game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "PQ_lista.h"
#include <fstream>

using namespace std;


gra::gra(){
    W=NULL;
    size=0;
    tab=NULL;
    goal=NULL;


}

gra::~gra(){

    for(int i=0;i<size;i++){
        delete []tab[i];
        delete []goal[i];
    }
    delete []tab;
    delete []goal;

    delete W;
}

void gra::wczytaj_tab(int **tablica,int N){
    if(size!=0){
        for(int i=0;i<size;i++){
            delete []tab[i];
            delete []goal[i];
        }
        delete []tab;
        delete []goal;
        //delete W;////////////////cos tu jest nie tak : (((

    }

    size=N;
    tab=new int*[size];
    goal=new int*[size];
    for(int i=0;i<size;i++){

        tab[i]=new int[size];
        goal[i]=new int[size];

    }
    int counter=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            tab[i][j]=tablica[i][j];
            if(tab[i][j]==0){x=i;y=j;}
            goal[i][j]=counter;
            counter++;
        }

    }
    goal[size-1][size-1]=0;
    if(solvable()){
        W=new AS(tab,goal,size);
    }

}

void gra::print_tab(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"|"<<setw(2)<<tab[i][j];
        }cout<<"|"<<endl;if(i<size-1){
            for(int k=0;k<size;k++){cout<<"---";}cout<<"-"<<endl;}
    }
    cout<<endl;
}

void gra::where_is_blank(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab[i][j]==0){x=i;y=j;}
        }
    }
}


void gra::left_tab(){
    if(size!=0){if(is==true){
            if(y>0){
                int pom=tab[x][y];
                tab[x][y]=tab[x][y-1];
                tab[x][y-1]=pom;
                y--;
            }
        }
    }

}

void gra::right_tab(){
    if(size!=0){if(is==true){
            if(y<size-1){
                int pom=tab[x][y];
                tab[x][y]=tab[x][y+1];
                tab[x][y+1]=pom;
                y++;}
        }}
}

void gra::up_tab(){
    if(size!=0){if(is==true){
            if(x>0){
                int pom=tab[x][y];
                tab[x][y]=tab[x-1][y];
                tab[x-1][y]=pom;
                x--;}
        }}
}

void gra::down_tab(){
    if(size!=0){if(is==true){
            if(x<size-1){
                int pom=tab[x][y];
                tab[x][y]=tab[x+1][y];
                tab[x+1][y]=pom;
                x++;}
        }}
}

int gra::hint_tab(){
    if(W!=NULL){if(is){
            W->status(tab);
            int pom=W->hint();
            if(pom==0){return tab[x][y-1];}
            if(pom==1){return tab[x][y+1];}
            if(pom==2){return tab[x-1][y];}
            if(pom==3){return tab[x+1][y];}
            return 0;
        }
        return 0;
    }
    return 0;
}

bool gra::solvable(){
    bool pom3=true;
    bool *pom2=new bool[size*size];
    for(int i=0;i<size*size;i++){
        pom2[i]=false;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab[i][j]<size*size and tab[i][j]>=0){pom2[tab[i][j]]=true;}
        }
    }
    for(int i=0;i<size*size;i++){
        if(pom2[i]==false)pom3=false;
    }
    delete []pom2;
    if(pom3==false) {is=false;return pom3;}

    int *pom=new int [size*size];
    int ilosc_zmian=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            pom[ilosc_zmian]=tab[i][j];
            ilosc_zmian++;
        }
    }
    ilosc_zmian=0;
    for (int i=0;i<(size*size)-1;i++)
        for (int j=i+1;j<size*size;j++)
            if (pom[j] && pom[i] &&pom[i] > pom[j])ilosc_zmian++;
    delete []pom;


    if(size==3){
        if(ilosc_zmian%2==0){is=true;return true;}
        else
        {is=false; return false;}}

    if(size==4){
        if (size & 1){
            is=!(ilosc_zmian & 1);
            return !(ilosc_zmian & 1);}

        else
        {

            if (x & 1){
                is=!(ilosc_zmian & 1);
                return !(ilosc_zmian & 1);}
            else{
                is=ilosc_zmian & 1;
                return ilosc_zmian & 1;}
        }

    }


}

void gra::rand_tab(){
    srand(time(0));
    int los;
    int ilosc_losow;
    //ilosc_losow=20+rand()%(100-20+1);
    ilosc_losow=50;
    for(int i=0;i<ilosc_losow;i++){
        los=rand()%(3-0+1);
        if(los==0){left_tab();}
        if(los==1){right_tab();}
        if(los==2){up_tab();}
        if(los==3){down_tab();}
    }
}

bool gra::compare_tab(int **tab1,int **tab2){
    bool g_state=true;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab1[i][j]!=tab2[i][j])g_state=false;
        }
    }return g_state;
}



void gra::save_solution(string nazwa){
    if(W!=NULL){if(is){
            ofstream plik;
            plik.open(nazwa.c_str());
            int **tablica=new int *[size];
            for(int i=0;i<size;i++){
                tablica[i]=new int[size];
            }
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    tablica[i][j]=tab[i][j];
                }
            }

            do{
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        plik<<setw(3)<<tab[i][j];
                    }if(i!=size)plik<<endl;
                }
                W->status(tab);
                if(W->hint()!=5){
                    plik<<endl;
                    plik<<"      |       "<<endl;
                    plik<<"      |       "<<endl;
                    plik<<"    __|__     "<<endl;
                    plik<<"    |||||     "<<endl;
                    plik<<"     |||      "<<endl;
                    plik<<"      |      "<<endl;
                    plik<<endl;

                }
                hint_tab();




            }
            while(W->hint()!=5);



            plik.close();
            wczytaj_tab(tablica,size);
            for(int i=0;i<size;i++){
                delete []tablica[i];

            }
            delete []tablica;


        }}
}

int gra::move_possibility(int k)
{   int ki,kj;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab[i][j]==k){
                ki=i;kj=j;
            }
        }

    }
    int sum=abs(ki-x)+abs(kj-y);
    if (sum==1){
        if(kj-y==-1){return 0;}
        if(kj-y==1){return 1;}
        if(ki-x==-1){return 2;}
        if(ki-x==1){return 3;}
    }
    else {
        return 5;
    }
}

