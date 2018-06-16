/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "travelagency.h"
#include "flightbooking.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
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
    connect(ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(on_actionRow_clicked(QTableWidgetItem*)));
    connect(ui->searchButton, SIGNAL(clicked(bool)),this,SLOT(on_searchbutton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionDateiEinlesen_clicked(){
    try{
    travelagency->readFile();
    }catch(runtime_error e){
        travelagency->reset();
        QMessageBox::information(this, tr("ERROR"), QString::fromStdString(e.what()));
    }
    double sumPrice = 0;
    for(unsigned int i = 0; i < travelagency->getAllBookings().size(); i++){
       sumPrice += travelagency->getAllBookings().at(i)->getPrice();
    }

    std::string ausgabe = "Es wurden " + travelagency->getSizeOfBookingsAsString() + " Buchungen, " + travelagency->getSizeOfCustomersAsString() + " Kunden und " + travelagency->getSizeOfTravelsAsString() +" Reisen im Gesamtwert von "+std::to_string(sumPrice)+" eingelesen";
     QMessageBox::information(this, tr("Einleseergebnis"), QString::fromStdString(ausgabe));

}

void MainWindow::on_actionBuchungenAnzeigen_clicked(){

    ui->tableWidget->setRowCount(travelagency->getAllBookings().size());
    QStringList headerLabels;
    headerLabels << "Buchungsnummer" << "Preis" << "Kunde";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    for(unsigned int i = 0; i < travelagency->getAllBookings().size(); i++){

        Travel* trav = travelagency->findTravel(travelagency->getAllBookings().at(i)->getTravelId());
        Customer* cust = travelagency->findCustomer(trav->getCustomerId());
        std::string customername = cust->getName();

        double price = travelagency->getAllBookings().at(i)->getPrice();
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << price;
        std::string priceText = stream.str();

        std::string bookingIdText = std::to_string(travelagency->getAllBookings().at(i)->getId());


        std::string rowText = bookingIdText + "\t\t" + priceText + "\t" + customername;

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

void MainWindow::on_actionRow_clicked(QTableWidgetItem *item)
{
    QTableWidgetItem* idCellObjPtr = ui->tableWidget->item(item->row(), 0);
    std::string id = idCellObjPtr->text().toStdString();
    Booking* book = travelagency->findBooking(stol(id));
    QDate fromDate = book->getFromDate();
    QDate toDate = book->getToDate();
    std::string price = std::to_string(book->getPrice());
    std::string travel = std::to_string(travelagency->findTravel(book->getTravelId())->getCustomerId());
    std::string customer = travelagency->findCustomer(travelagency->findTravel(book->getTravelId())->getCustomerId())->getName();

    ui->lineEdit->setText(QString::fromStdString(id));
    ui->priceField->setText(QString::fromStdString(price));
    ui->travelField->setText(QString::fromStdString(travel));
    ui->customerField->setText(QString::fromStdString(customer));

    ui->calendarWidgetFromDate->setSelectedDate(fromDate);

    ui->calendarWidgetToDate->setSelectedDate(toDate);
    vector<string> infos = travelagency->getTypeAndInfo(stol(id));
    if (infos.at(0)=="F"){
        ui->fromDestDetailsField->setText(QString::fromStdString(infos.at(1)));
        ui->toDestDetailsField->setText(QString::fromStdString(infos.at(2)));
        ui->airlineDetailsField->setText(QString::fromStdString(infos.at(3)));
        ui->seatPrefDetailsField->setText(QString::fromStdString(infos.at(4)));
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(infos.at(0)=="R"){
        ui->pickupDestinationDetailsField->setText(QString::fromStdString(infos.at(1)));
        ui->returnLocationDetailsField->setText(QString::fromStdString(infos.at(2)));
        ui->CompanyDetailField->setText(QString::fromStdString(infos.at(3)));
        ui->insuranceTypeDetailsField->setText(QString::fromStdString(infos.at(4)));
        ui->stackedWidget->setCurrentIndex(2);
    }
    if(infos.at(0)=="H"){
        ui->hotelNameDetailField->setText(QString::fromStdString(infos.at(1)));
        ui->cityNameDetailField->setText(QString::fromStdString(infos.at(2)));
        ui->smokeDetailField->setText(QString::fromStdString(infos.at(3)));
        ui->stackedWidget->setCurrentIndex(1);
    }

}

void MainWindow::on_searchbutton_clicked(){
    vector<Customer*> customers = travelagency->searchFunction((ui->searchbar->text()).toStdString());
    string ausgabe = "ID\tName\n";
    for(unsigned int i = 0; i < customers.size(); i++){
        ausgabe = ausgabe + std::to_string(customers.at(i)->getId()) + "\t" + customers.at(i)->getName()+"\n";
    }
    QMessageBox::information(this, tr("test"), QString::fromStdString(ausgabe));
}
