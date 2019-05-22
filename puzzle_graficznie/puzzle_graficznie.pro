#-------------------------------------------------
#
# Project created by QtCreator 2019-04-23T17:49:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puzzle_graficznie
TEMPLATE = app


SOURCES += main.cpp\
        PQ_lista.cpp \
        mainwindow.cpp \
        puzzle_game.cpp \
        puzzle_solver.cpp \
        secondwindow.cpp

HEADERS  += mainwindow.h \
    PQ_lista.h \
    puzzle_game.h \
    puzzle_solver.h \
    secondwindow.h

FORMS    += mainwindow.ui \
    secondwindow.ui
