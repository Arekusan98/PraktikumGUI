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
#include "traveltest.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    TravelAgencyTest travelAgencyTest;
    QTest::qExec(&travelAgencyTest);

    TravelTest travelTest;
    QTest::qExec(&travelTest);
    return a.exec();
}
