/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "booking.h"

Booking::Booking()
{

}
void Booking::set(long id, double price, string fromDate, string toDate, long travelId){
    this->id = id;
    this->price = price;
    this->fromDate.setDate(stoi(fromDate.substr(0,4)), stoi(fromDate.substr(4,2)), stoi(fromDate.substr(6,2)));

    this->toDate.setDate(stoi(toDate.substr(0,4)), stoi(toDate.substr(4,2)), stoi(toDate.substr(6,2)));

    this->travelId = travelId;
}
long Booking::getId(){
    return this->id;
}

double Booking::getPrice()
{
    return price;
}

long Booking::getTravelId()
{
    return travelId;
}

QDate Booking::getFromDate()
{
    return fromDate;
}

QDate Booking::getToDate()
{
    return toDate;
}


