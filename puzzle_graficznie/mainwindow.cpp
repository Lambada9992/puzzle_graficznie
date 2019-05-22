#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ctime>
#include <cstdlib>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    size_icon=64;
    size_game=3;
    x0=2;y0=2;

    //wczytywanie do gry
    load_to_game(1,2,3,4,5,6,7,8,0);


    //do animacji
    a_pole=new QPropertyAnimation *[size_icon*size_icon];
    a_pole[0]=nullptr;
    a_pole[1] = new QPropertyAnimation(ui->pole_1,"geometry");
    a_pole[2] = new QPropertyAnimation(ui->pole_2,"geometry");
    a_pole[3] = new QPropertyAnimation(ui->pole_3,"geometry");
    a_pole[4] = new QPropertyAnimation(ui->pole_4,"geometry");
    a_pole[5] = new QPropertyAnimation(ui->pole_5,"geometry");
    a_pole[6] = new QPropertyAnimation(ui->pole_6,"geometry");
    a_pole[7] = new QPropertyAnimation(ui->pole_7,"geometry");
    a_pole[8] = new QPropertyAnimation(ui->pole_8,"geometry");

    for(int i=1;i<size_icon*size_icon;i++)

    a_pole[1]->setDuration(500);
    a_pole[2]->setDuration(500);
    a_pole[3]->setDuration(500);
    a_pole[4]->setDuration(500);
    a_pole[5]->setDuration(500);
    a_pole[6]->setDuration(500);
    a_pole[7]->setDuration(500);
    a_pole[8]->setDuration(500);
    //

}

MainWindow::~MainWindow()
{
    for(int i=0;i<size_game*size_game;i++){
        delete a_pole[i];
    }
    delete ui;
}

void MainWindow::load_to_game(int t0,int t1,int t2,int t3,int t4,int t5,int t6,int t7,int t8)
{

    int **pom=new int *[size_game];
    for(int i=0;i<size_game;i++){
        pom[i]=new int[size_game];

    }
    pom[0][0]=t0;pom[0][1]=t1;pom[0][2]=t2;
    pom[1][0]=t3;pom[1][1]=t4;pom[1][2]=t5;
    pom[2][0]=t6;pom[2][1]=t7;pom[2][2]=t8;
    for(int i=0;i<size_game;i++){
        for(int j=0;j<size_game;j++){
            if(pom[i][j]==0){x0=i;y0=j;break;}
        }

    }



    game.wczytaj_tab(pom,size_game);
    for(int i=0;i<size_game;i++){
        delete []pom[i];
    }
    delete []pom;
    set_buttons();


}

void MainWindow::set_buttons()
{   int x1,x2,x3,x4,x5,x6,x7,x8;
    int y1,y2,y3,y4,y5,y6,y7,y8;
    for(int i=0;i<size_game;i++){
        for(int j=0;j<size_game;j++){
            if(game.tab[i][j]==1){x1=i;y1=j;}
            if(game.tab[i][j]==2){x2=i;y2=j;}
            if(game.tab[i][j]==3){x3=i;y3=j;}
            if(game.tab[i][j]==4){x4=i;y4=j;}
            if(game.tab[i][j]==5){x5=i;y5=j;}
            if(game.tab[i][j]==6){x6=i;y6=j;}
            if(game.tab[i][j]==7){x7=i;y7=j;}
            if(game.tab[i][j]==8){x8=i;y8=j;}
            if(game.tab[i][j]==0){x0=i;y0=j;}
        }
    }
    ui->pole_1->setGeometry(y1*size_icon,x1*size_icon,size_icon,size_icon);
    ui->pole_2->setGeometry(y2*size_icon,x2*size_icon,size_icon,size_icon);
    ui->pole_3->setGeometry(y3*size_icon,x3*size_icon,size_icon,size_icon);
    ui->pole_4->setGeometry(y4*size_icon,x4*size_icon,size_icon,size_icon);
    ui->pole_5->setGeometry(y5*size_icon,x5*size_icon,size_icon,size_icon);
    ui->pole_6->setGeometry(y6*size_icon,x6*size_icon,size_icon,size_icon);
    ui->pole_7->setGeometry(y7*size_icon,x7*size_icon,size_icon,size_icon);
    ui->pole_8->setGeometry(y8*size_icon,x8*size_icon,size_icon,size_icon);


}

void MainWindow::move(int u)
{

    int k=game.move_possibility(u);


    if(k!=5){
        if(k==0){game.left_tab();}
        if(k==1){game.right_tab();}
        if(k==2){game.up_tab();}
        if(k==3){game.down_tab();}
        a_pole[u]->setStartValue(QRect(game.y*size_icon,game.x*size_icon,size_icon,size_icon));
        a_pole[u]->setEndValue(QRect(y0*size_icon,x0*size_icon,size_icon,size_icon));
        a_pole[u]->start();
        y0=game.y;
        x0=game.x;
        }

    }


void MainWindow::on_pole_1_clicked()
{

    move(1);

}

void MainWindow::on_pole_2_clicked()
{

    move(2);
}

void MainWindow::on_pole_3_clicked()
{move(3);

}

void MainWindow::on_pole_4_clicked()
{move(4);

}

void MainWindow::on_pole_5_clicked()
{move(5);

}

void MainWindow::on_pole_6_clicked()
{move(6);

}

void MainWindow::on_pole_7_clicked()
{   move(7);

}

void MainWindow::on_pole_8_clicked()
{ move(8);

}

void MainWindow::on_przycisk_hint_clicked()
{
    int k=game.hint_tab();
    if(k!=0){move(k);}
}

void MainWindow::on_przycisk_solve_clicked()
{
    int k=game.hint_tab();
    while(k!=0){
        k=game.hint_tab();
        if(k!=0)
        {move(k);}
    }


}

void MainWindow::on_randomize_clicked()
{int pom;
    for(int i=0;i<1000;i++){
        pom=1+rand()%(8-1+1);
        move(pom);
    }

}
