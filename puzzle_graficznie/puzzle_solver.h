#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#include <iostream>


using namespace std;

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
    astar(int **,int,astar * =NULL);
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

class AS{
    int size;
    int **tab;
    int **goal;
    astar *podpowiedz;
public:
    AS(int **,int **,int);
    ~AS();

    int hint();
    void status(int **);
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
