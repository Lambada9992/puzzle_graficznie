/**
 * \file PQ_lista.cpp
 * \brief Plik nagłówkowy modułu \a PQ_lista.
 *
 * Moduł \a PQ_lista zawiera definicję Kolejki priorytetowej
 * oraz zestaw funkcji służących do zarządzania tą kolejka
 *
 * \see PQ_lista.h
 */

#include <iostream>
#include <PQ_lista.h>

using namespace std;

////////////STRUKTURA////////
lista::lista(astar *elem,int N){
    next=NULL;
    down=NULL;
    key=N;
    element=elem;



}

///////////////|PQ\/////////////
PQ_lista::PQ_lista(){
    H=NULL;
}


void PQ_lista::insert(astar *x,int N){
    if(H==NULL){
        H=new lista(x,N);
    }
    else{

        lista *new_node=new lista(x,N);
        if(H->key>N){
            new_node->down=H;
            H=new_node;
        }else{if(H->key==N){
                new_node->next=H;
                new_node->down=H->down;
                H->down=NULL;
                H=new_node;
            }
            else{
                lista *pom=H;
                while(pom!=NULL){

                    if(pom->down==NULL){
                        pom->down=new_node;

                        break;
                    }

                    if(pom->down->key==N){

                        new_node->next=pom->down;
                        new_node->down=pom->down->down;
                        pom->down->down=NULL;
                        pom->down=new_node;
                        break;}

                    if(pom->down->key>N){

                        new_node->down=pom->down;
                        pom->down=new_node;
                        break;
                    }

                    pom=pom->down;
                }

            }
        }
    }


}
astar *PQ_lista::extract_min(){


    if(H==NULL)return NULL;
    lista*pom=H;

    if(H->next!=NULL){
        H->next->down=H->down;
        H=H->next;
        pom->next=NULL;
        pom->down=NULL;
        astar *pom2=pom->element;
        delete pom;
        return pom2;
    }
    else{
        H=H->down;
        astar *pom2=pom->element;
        pom->next=NULL;
        pom->down=NULL;
        delete pom;
        return pom2;
    }


}
astar *PQ_lista::min(){
    if(H==NULL){return NULL;}else
    {
        return H->element;
    }
}
void PQ_lista::usun(){
    if(H!=NULL){
        lista *pom=H;
        while(H!=NULL){
            pom=H;
            H=H->down;
            usun_next(pom);

        }
    }
}
void PQ_lista::usun_next(lista *&X){
    lista *pom;
    while (X!=NULL){
        pom =X;

        X=X->next;
        delete pom;
    }
}
