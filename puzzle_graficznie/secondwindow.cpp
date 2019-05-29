/**
 * \file secondwindow.cpp
 * \brief Plik implementacji modułu \a mainwindow.
 *
 * Moduł \a mainwindow zawiera interfejs graficzny oraz funkcje
 * okna wczytywania nowego stanu gry
 *
 *
 * \see secondwindow.h
 */

#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    wczytaj_combo();
    zmiana=false;


}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::wczytaj_liczby(QComboBox *box)
{
box->addItem(" ");
box->addItem("1");
box->addItem("2");
box->addItem("3");
box->addItem("4");
box->addItem("5");
box->addItem("6");
box->addItem("7");
box->addItem("8");




}

void secondwindow::wczytaj_combo()
{
    wczytaj_liczby(ui->comboBox_1);
    wczytaj_liczby(ui->comboBox_2);
    wczytaj_liczby(ui->comboBox_3);
    wczytaj_liczby(ui->comboBox_4);
    wczytaj_liczby(ui->comboBox_5);
    wczytaj_liczby(ui->comboBox_6);
    wczytaj_liczby(ui->comboBox_7);
    wczytaj_liczby(ui->comboBox_8);
    wczytaj_liczby(ui->comboBox_9);


}

int secondwindow::string_to_int(QString pom)
{   if(pom==" "){return 0;}
    else{
        return pom.toInt();
    }

}

bool secondwindow::get_zmiana()const
{
    return zmiana;

}

int secondwindow::get_pole1()
{
    return string_to_int(ui->comboBox_1->currentText());
}
int secondwindow::get_pole2()
{
    return string_to_int(ui->comboBox_2->currentText());
}
int secondwindow::get_pole3()
{
    return string_to_int(ui->comboBox_3->currentText());
}
int secondwindow::get_pole4()
{
    return string_to_int(ui->comboBox_4->currentText());
}
int secondwindow::get_pole5()
{
    return string_to_int(ui->comboBox_5->currentText());
}
int secondwindow::get_pole6()
{
    return string_to_int(ui->comboBox_6->currentText());
}
int secondwindow::get_pole7()
{
    return string_to_int(ui->comboBox_7->currentText());
}
int secondwindow::get_pole8()
{
    return string_to_int(ui->comboBox_8->currentText());
}
int secondwindow::get_pole9()
{
    return string_to_int(ui->comboBox_9->currentText());
}


void secondwindow::on_Wczytaj_clicked()
{   int tab[3][3];
    tab[0][0]=string_to_int(ui->comboBox_1->currentText());tab[0][1]=string_to_int(ui->comboBox_2->currentText());tab[0][2]=string_to_int(ui->comboBox_3->currentText());
    tab[1][0]=string_to_int(ui->comboBox_4->currentText());tab[1][1]=string_to_int(ui->comboBox_5->currentText());tab[1][2]=string_to_int(ui->comboBox_6->currentText());
    tab[2][0]=string_to_int(ui->comboBox_7->currentText());tab[2][1]=string_to_int(ui->comboBox_8->currentText());tab[2][2]=string_to_int(ui->comboBox_9->currentText());

    bool pom=true;
    bool *tabpom=new bool[9];
    for(int i=0;i<9;i++){
        tabpom[i]=false;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(tab[i][j]<9 and tab[i][j]>=0){tabpom[tab[i][j]]=true;}
        }
    }
    for(int i=0;i<9;i++){
        if(tabpom[i]==false)pom=false;
    }
    delete []tabpom;
    if(pom==true){zmiana=true;}else{zmiana=false;}



    this->close();


}

void secondwindow::on_Anuluj_clicked()
{
    this->close();
}
