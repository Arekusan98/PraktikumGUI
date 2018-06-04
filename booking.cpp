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
    this->fromDate = fromDate;
    this->toDate = toDate;
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

string Booking::getFromDate()
{
    return fromDate;
}

string Booking::getToDate()
{
    return toDate;
}


