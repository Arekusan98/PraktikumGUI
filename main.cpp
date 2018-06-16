/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "mainwindow.h"
#include <QApplication>
#include "travelagencytest.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TravelAgencyTest test;
    QTest::qExec(&test);
    return a.exec();
}
