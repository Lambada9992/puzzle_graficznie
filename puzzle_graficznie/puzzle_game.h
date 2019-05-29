/**
 * \file puzzle_game.h
 * \brief Plik nagłówkowy modułu \a puzzle_game.
 *
 * Moduł \a puzzle_game zawiera definicję klasy gra(8 puzzle)
 * (zawiera pole gry oraz funkcje pozwalające na gre takie jak ruchy)
 *
 * \see PQ_lista.cpp
 */

#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <iostream>
#include <puzzle_solver.h>
#include <QFile>

using namespace std;

/**
 * @brief The gra class
 * klasa gra odpowiada za gre 8-puzzle
 */
class gra{
public:
    int **goal;
    int size;
    int **tab;

    int x;
    int y;
    bool is;
    bool is_move;
private:
    AS *W;
    /**
     * @brief where_is_blank Funkcja ustalająca pozycje pustego pola
     */
    void where_is_blank();
    /**
     * @brief solvable Funkcja sprawdza czy da się rozwiazac gre
     * @return zwraca T/F czy gra jest rozwiązywalna
     */
    bool solvable();
    /**
     * @brief compare_tab Funkcja poruwnująca dwa stany gry(2 tablice)
     * @return T=takie same tablice,F-nie takie same
     */
    bool compare_tab(int **,int **);
public:
    /**
     * @brief wczytaj_tab wczytuje tablice do gry
     * @param tab wczytywana tablica
     * @param N wymiar tablicy
     */
    void wczytaj_tab(int **tab,int N);
    /**
     * @brief left_tab ruch w lewo
     */
    void left_tab();
    /**
     * @brief left_tab ruch w prawo
     */
    void right_tab();
    /**
     * @brief left_tab ruch w góre
     */
    void up_tab();
    /**
     * @brief left_tab ruch w dół
     */
    void down_tab();
    /**
     * @brief hint_tab Funkcja wykonująca podpowiedz
     * @return zwraca pole którym należy się ruszyc
     */
    int hint_tab();
    /**
     * @brief save_solution Zapisuje rozwiazanie aktualnego stanu gry do pliku
     * @return czy udalo się zapisac do pliku czy nie
     */
    bool save_solution(QString);
    /**
     * @brief move_possibility Funkcja sprawdzajaca czy mozna się ruszyc danym polem
     * @return zwraca kierunek ruchu mozliwego tym polem 0-lewo 1-praw 2-góra 3-dół 5-brak mozliwosci ruchu
     */
    int move_possibility(int);

    gra();
    ~gra();

};


#endif // PUZZLE_GAME_H
