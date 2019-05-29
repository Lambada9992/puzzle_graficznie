/**
 * \file secondwindow.h
 * \brief Plik implementacji modułu \a mainwindow.
 *
 * Moduł \a mainwindow zawiera interfejs graficzny oraz funkcje
 * okna wczytywania nowego stanu gry
 *
 *
 * \see secondwindow.cpp
 */

#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();
    /**
     * @brief get_zmiana
     * @return zwraca T-jeśli tablice nalezy wczytac / F-jezeli nie
     */
    bool get_zmiana()const;
    /// zwraca jaka liczba znajdywala się w polu 1
    int get_pole1();
    /// zwraca jaka liczba znajdywala się w polu 2
    int get_pole2();
    /// zwraca jaka liczba znajdywala się w polu 3
    int get_pole3();
    /// zwraca jaka liczba znajdywala się w polu 4
    int get_pole4();
    /// zwraca jaka liczba znajdywala się w polu 5
    int get_pole5();
    /// zwraca jaka liczba znajdywala się w polu 6
    int get_pole6();
    /// zwraca jaka liczba znajdywala się w polu 7
    int get_pole7();
    /// zwraca jaka liczba znajdywala się w polu 8
    int get_pole8();
    /// zwraca jaka liczba znajdywala się w polu 9
    int get_pole9();



private slots:


    void on_Wczytaj_clicked();

    void on_Anuluj_clicked();

private:
    Ui::secondwindow *ui;
    bool zmiana;
    int pole1;
    int pole2;
    int pole3;
    int pole4;
    int pole5;
    int pole6;
    int pole7;
    int pole8;
    int pole9;

    void wczytaj_liczby(QComboBox *);
    void wczytaj_combo();
    int string_to_int(QString);


};

#endif // SECONDWINDOW_H
