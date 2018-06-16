/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include "travelagency.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Customer* findCustomer (long id);
    Travel* findTravel (long id);
    Booking* findBooking (long id);

private:
    Ui::MainWindow *ui;
    TravelAgency* travelagency = new TravelAgency();

private slots:
    void on_actionDateiEinlesen_clicked();
    void on_actionBuchungenAnzeigen_clicked();
    void on_actionProgrammBeenden_clicked();
    void on_searchbutton_clicked();
    void on_actionRow_clicked(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
