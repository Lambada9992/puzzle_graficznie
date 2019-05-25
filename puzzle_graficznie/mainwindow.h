#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <puzzle_game.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void load_to_game(int,int,int,int,int,int,int,int,int);
    void set_buttons();
    void move(int);
    
private slots:


    void on_pole_1_clicked();

    void on_pole_2_clicked();

    void on_pole_3_clicked();

    void on_pole_4_clicked();

    void on_pole_5_clicked();

    void on_pole_6_clicked();

    void on_pole_7_clicked();

    void on_pole_8_clicked();

    void on_przycisk_hint_clicked();

    void on_przycisk_solve_clicked();

    void on_randomize_clicked();


    void on_actionZapisz_rozwi_zanie_triggered();

    void on_actionWczytaj_gr_triggered();

private:
    Ui::MainWindow *ui;

    gra game;
    int x0,y0;



    int size_icon;
    int size_game;

    QPropertyAnimation **a_pole;
    QSequentialAnimationGroup *group_animation;




};

#endif // MAINWINDOW_H
