#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <iostream>
#include <puzzle_solver.h>

using namespace std;

class gra{

    int **goal;
public:
    int size;
    int **tab;


    int x;
    int y;
    bool is;
private:
    AS *W;

    //dzialanie//


    void where_is_blank();
    bool solvable();
    bool compare_tab(int **,int **);
public:
    void wczytaj_tab(int **,int);
    void rand_tab();
    void left_tab();
    void right_tab();
    void up_tab();
    void down_tab();
    int hint_tab();
    void save_solution(string);//DO POPRAWY
    int move_possibility(int);

    gra();
    ~gra();
    //wyswietlanie//
    void print_tab();




};


#endif // PUZZLE_GAME_H
