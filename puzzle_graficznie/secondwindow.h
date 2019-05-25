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
    void wczytaj_liczby(QComboBox *);
    void wczytaj_combo();
    int string_to_int(QString);
    bool get_zmiana()const;
    int get_pole1();
    int get_pole2();
    int get_pole3();
    int get_pole4();
    int get_pole5();
    int get_pole6();
    int get_pole7();
    int get_pole8();
    int get_pole9();



private slots:


    void on_Wczytaj_clicked();

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


};

#endif // SECONDWINDOW_H
