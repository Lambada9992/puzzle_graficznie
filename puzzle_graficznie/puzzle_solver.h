/**
 * \file puzzle_solver.h
 * \brief Plik nagłówkowy modułu \a puzzle_game.
 *
 * Moduł \a puzzle_game zawiera definicję klasy Astar i AS
 * które odpowiadaja za system znajdywania rozwiązania gry(8 puzzle)
 *
 * \see puzzle_solver.cpp
 */
#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#include <iostream>


using namespace std;
/**
 * @brief Klasa astar przechowuje pojedyncze elementy potrzebne do algorytmu A*
 */
class astar{
    int size;
    int **tab;
    int x;
    int y;
    int g;
    int h;
    int f;
    astar *parent;
    astar *next;


public:
    /**
     * @brief astar konstruktor
     * @param tab pole na umieszczenie tablicy(gry) jaką chcemy w tym elemencie
     * @param size  przyjmuje wartosc int wymiaru gry np 3 jezeli mamy do czynienia z plansza 3na3
     * @param parent przyjmuje wskaźnik na element astar(na rodzica danego elementu czyli ruch poprzedni)
     */
    astar(int **tab,int size,astar *parent =NULL);
    ~astar();
private:
    bool check_left();
    bool check_right();
    bool check_up();
    bool check_down();

    void left_tab();
    void right_tab();
    void up_tab();
    void down_tab();

    void manhattan(int **);
    bool compare_tab(astar *);

    friend class AS;

};
/**
 * @brief klasa wykonująca Algorytm A*(system rozwiązujący grę)
 */
class AS{
    int size;
    int **tab;
    int **goal;
    astar *podpowiedz;
public:
    /**
     * @brief AS kostruktor klasy astar
     * @param tab aktualny stan gry(tablica)
     * @param goal Cel gry który chcemy osiągnac(tablica)
     * @param size wymiar gry
     */
    AS(int **tab,int **goal,int size);
    ~AS();
    /**
     * @brief hint Wskazuje podpowiedz
     * @return pole którym należy się ruszyć(np liczbe 4 jezeli nalezy się ruszyc polem z cyfra 4)
     */
    int hint();
    /**
     * @brief status porownoje oraz sprawdza aktualny stan gry z przechowywanym rozwiązaniem i w razie czego modyfikuje je
     * @param tab miejsce na przekazanie aktualnej tablicy gry
     */
    void status(int **tab);
private:
    void zwracanie_wyniku(astar *);
    void solve();
    bool child(astar *&,astar ******);
    bool compare(int **,int **);

    astar ******make_hash();
    void delete_hash(astar ******&);
    void add_hash(astar *,astar ******&);
    bool exist_hash(astar *,astar ******&);

};



#endif // PUZZLE_SOLVER_H
