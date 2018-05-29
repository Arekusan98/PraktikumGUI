/*
 * Praktikum 3
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "travelagency.h"
#include <iomanip>
#include <sstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionDatei_einlesen, SIGNAL(triggered(bool)),this,SLOT(on_actionDateiEinlesen_clicked()));
    connect(ui->actionBuchungen_anzeigen, SIGNAL(triggered(bool)),this,SLOT(on_actionBuchungenAnzeigen_clicked()));
    connect(ui->actionProgramm_beenden, SIGNAL(triggered(bool)),this,SLOT(on_actionProgrammBeenden_clicked()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(on_actionItem_clicked(QListWidgetItem*)));
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(on_actionRow_clicked(QTableWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionDateiEinlesen_clicked(){
    travelagency->readFile();
    double sumPrice = 0;
    for(unsigned int i = 0; i < travelagency->getAllBookings().size(); i++){
       sumPrice += travelagency->getAllBookings().at(i)->getPrice();
    }

    std::string ausgabe = "Es wurden " + std::to_string(travelagency->getAllBookings().size()) + " Buchungen, " + std::to_string(travelagency->getAllCustomers().size()) + " Kunden und " + std::to_string(travelagency->getAllTravels().size()) +" Reisen im Gesamtwert von "+std::to_string(sumPrice)+" eingelesen";
     QMessageBox::information(this, tr("Einleseergebnis"), QString::fromStdString(ausgabe));

}

void MainWindow::on_actionBuchungenAnzeigen_clicked(){

    QString header;
    header = "Buchungsnummer\tPreis\tKunde";
    ui->listWidget->addItem(header);
    ui->tableWidget->setRowCount(travelagency->getAllBookings().size());
    QStringList headerLabels;
    headerLabels << "Buchungsnummer" << "Preis" << "Kunde";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    for(unsigned int i = 0; i < travelagency->getAllBookings().size(); i++){

        long travelid = travelagency->getAllBookings().at(i)->getTravelId();
        Travel* trav = travelagency->findTravel(travelid);
        long customerid = trav->getCustomerId();
        Customer* cust = travelagency->findCustomer(customerid);
        std::string customername = cust->getName();

        double price = travelagency->getAllBookings().at(i)->getPrice();
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << price;
        std::string priceText = stream.str();

        std::string bookingIdText = std::to_string(travelagency->getAllBookings().at(i)->getId());


        std::string rowText = bookingIdText + "\t\t" + priceText + "\t" + customername;
        QListWidgetItem* newItem = new QListWidgetItem(QString::fromStdString(rowText), ui->listWidget);
        ui->listWidget->addItem(newItem);

        QTableWidgetItem* newBookingCellItem = new QTableWidgetItem(QString::fromStdString(bookingIdText));
        QTableWidgetItem* newPriceCellItem = new QTableWidgetItem(QString::fromStdString(priceText));
        QTableWidgetItem* newNameCellItem = new QTableWidgetItem(QString::fromStdString(customername));



        ui->tableWidget->setItem(i, 0, newBookingCellItem);
        ui->tableWidget->setItem(i, 1, newPriceCellItem);
        ui->tableWidget->setItem(i, 2, newNameCellItem);
    }

}

void MainWindow::on_actionProgrammBeenden_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionItem_clicked(QListWidgetItem* item)
{
    std::string id = item->text().split("\t")[0].toStdString();
    Booking* book = travelagency->findBooking(stol(id));
    std::string fromDate = book->getFromDate();
    std::string toDate = book->getToDate();

    ui->lineEdit->setText(item->text().split("\t")[0]);

    std::string year = fromDate.substr(0,4);
    std::string month = fromDate.substr(4,2);
    std::string day = fromDate.substr(6,2);
    QDate qFromDate;
    qFromDate.setDate(stoi(year), stoi(month), stoi(day));
    ui->calendarWidgetFromDate->setSelectedDate(qFromDate);

    year = toDate.substr(0,4);
    month = toDate.substr(4,2);
    day = toDate.substr(6,2);
    QDate qToDate;
    qToDate.setDate(stoi(year), stoi(month), stoi(day));
    ui->calendarWidgetToDate->setSelectedDate(qToDate);
}

void MainWindow::on_actionRow_clicked(QTableWidgetItem *item)
{
    QTableWidgetItem* idCellObjPtr = ui->tableWidget->item(item->row(), 0);
    std::string id = idCellObjPtr->text().toStdString();
    Booking* book = travelagency->findBooking(stol(id));
    std::string fromDate = book->getFromDate();
    std::string toDate = book->getToDate();

    ui->lineEdit->setText(QString::fromStdString(id));

    std::string year = fromDate.substr(0,4);
    std::string month = fromDate.substr(4,2);
    std::string day = fromDate.substr(6,2);
    QDate qFromDate;
    qFromDate.setDate(stoi(year), stoi(month), stoi(day));
    ui->calendarWidgetFromDate->setSelectedDate(qFromDate);

    year = toDate.substr(0,4);
    month = toDate.substr(4,2);
    day = toDate.substr(6,2);
    QDate qToDate;
    qToDate.setDate(stoi(year), stoi(month), stoi(day));
    ui->calendarWidgetToDate->setSelectedDate(qToDate);
}



