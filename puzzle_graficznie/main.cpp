/**
* \mainpage
* \par 8-puzzle
* Gra 8-puzzle z funkcja podpowiedzi wykorzystujaca algorytm A*
* \author Marcin Bobiński
* \date 2019.05.28
* \version 1.0
* \par Kontakt:
* \a marcin.bobinki9992@gmail.com
*/

/**
 * \file main.cpp
 * \brief Plik z funkcją main(int argc, char* argv[])
 */


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
