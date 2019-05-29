/**
 * \file PQ_lista.h
 * \brief Plik nagłówkowy modułu \a PQ_lista.
 *
 * Moduł \a PQ_lista zawiera definicję Kolejki priorytetowej
 * oraz zestaw funkcji służących do zarządzania tą kolejka
 *
 * \see PQ_lista.cpp
 */


#ifndef PQ_LISTA_H
#define PQ_LISTA_H

#include <iostream>
#include <puzzle_solver.h>

using namespace std;
/**
 * @brief The lista class
 *
 * Definicja pojedyńczego elementu kolejki priorytetowej
 */
class lista{
    /// klucz wartościujacy priorytet przechowywanego elementu
    int key;
    /// przechowywany element
    astar* element;
    /// wskaźnik na kolejny element o tej samej wartosci klucza
    lista* next;
    /// wskaznik na element o wyzszej wartosci klucza
    lista* down;

    /**
     * @brief lista konstruktor pojedynczego elementu
     * @param element element przechowywany
     * @param N priorytet
     */
    lista(astar *element,int N);

    friend class PQ_lista;
};
/**
 * @brief The PQ_lista class
 *
 * klasa służaca za przechowywanie całej kolejki priorytetowej oraz obsługi jej
 */
class PQ_lista{
    /// wskaznik na 1 element kolejki priorytetowej (o najnizszym kluczu)
    lista *H;
public:
    /**
     * @brief PQ_lista konstruktor
     */
    PQ_lista();
    /**
     * @brief insert funkcja dodajaca element do kolejki priorytetowej
     * @param element element przekazywany
     * @param N priorytetet elementu
     */
    void insert(astar*element,int N);
    /**
     * @brief extract_min funkcja zwracająca najmniejszy element listy(usuwa go z niej)
     * @return zwraca wskaźnik na najmniejszy element kolejki
     */
    astar *extract_min();
    /**
     * @brief min funkcja zwracająca najmniejszy element listy(NIEusuwa go z niej)
     * @return zwraca wskaźnik na najmniejszy element kolejki
     */
    astar *min();
    /**
     * @brief usun funkcja usuwająca kolejke priorytetową
     */
    void usun();
    /**
     * @brief usun_next funkcja usuwająca wszystkie elemnety kolejki priorytetowej o tej samej wartości klucza
     */
    void usun_next(lista *&);

};





#endif // PQ_LISTA_H
