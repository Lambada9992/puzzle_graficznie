/**
 * \file mainwindow.h
 * \brief Plik implementacji modułu \a mainwindow.
 *
 * Moduł \a mainwindow zawiera interfejs graficzny z wszystkimi funkcjami glownego okna
 *
 *
 * \see mainwindow.cpp
 */


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

/**
 * @brief The MainWindow class
 * klasa odpowiedzialna za interfejs graficzny
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief load_to_game Funkcja ładująca grę zadana przez uzytkownika
     *
     * ładuje ją do interfejsu graficznego oraz do klasy gra
     * @param p1 liczba stojąca na 1 polu
     * @param p2 liczba stojąca na 2 polu
     * @param p3 liczba stojąca na 3 polu
     * @param p4 liczba stojąca na 4 polu
     * @param p5 liczba stojąca na 5 polu
     * @param p6 liczba stojąca na 6 polu
     * @param p7 liczba stojąca na 7 polu
     * @param p8 liczba stojąca na 8 polu
     * @param p9 liczba stojąca na 9 polu
     */
    void load_to_game(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9);
    /**
     * @brief set_buttons Funkcja ustawiająca przyciski
     *
     * ustawia przyciski w interfejsie graficznym
     */
    void set_buttons();
    /**
     * @brief move Funkcja wykonywująca ruch gracza w grze
     * @param liczba mowiaca ktore pole ma wykonac ruch
     */

    void move(int liczba);
    
private slots:

    /// przycisk pole 1 (wywołuje funkcje move tego pola)
    void on_pole_1_clicked();
    /// przycisk pole 2 (wywołuje funkcje move tego pola)
    void on_pole_2_clicked();
    /// przycisk pole 3 (wywołuje funkcje move tego pola)
    void on_pole_3_clicked();
    /// przycisk pole 4 (wywołuje funkcje move tego pola)
    void on_pole_4_clicked();
    /// przycisk pole 5 (wywołuje funkcje move tego pola)
    void on_pole_5_clicked();
    /// przycisk pole 6 (wywołuje funkcje move tego pola)
    void on_pole_6_clicked();
    /// przycisk pole 7 (wywołuje funkcje move tego pola)
    void on_pole_7_clicked();
    /// przycisk pole 8 (wywołuje funkcje move tego pola)
    void on_pole_8_clicked();
    /**
     * @brief on_przycisk_hint_clicked
     * funkcja wykonująca podpowiedz w grze
     */
    void on_przycisk_hint_clicked();
    /**
     * @brief on_przycisk_solve_clicked
     * funkcja rozwiazywujaca gre
     */
    void on_przycisk_solve_clicked();
    /**
     * @brief on_randomize_clicked
     * funkcja wykonująca losowe ruchy w grze
     */
    void on_randomize_clicked();

    /**
     * @brief on_actionZapisz_rozwi_zanie_triggered
     * zapisuje do pliku rozwiązanie aktualnej gry
     */

    void on_actionZapisz_rozwi_zanie_triggered();
    /**
     * @brief on_actionWczytaj_gr_triggered
     * wywołuje nowe okno gdzie mozna podac nowa gre oraz wczytuje ją
     */
    void on_actionWczytaj_gr_triggered();
    /// exit
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    /// Gra (logiczny element gry)
    gra game;
    ///wspolrzedna X pustego pola
    int x0;
    ///wspolrzedna Y pustego pola
    int y0;
    ///rozmiar przycisku gry w pixelach
    int size_icon;
    ///wymiar gry
    int size_game;
    ///animacje przycisków
    QPropertyAnimation **a_pole;





};

#endif // MAINWINDOW_H
