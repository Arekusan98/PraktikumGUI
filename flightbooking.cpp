/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

void FlightBooking::set(string fromDest, string toDest, string airline, char seatPref){

    this->fromDest = fromDest;
    this->toDest = toDest;
    this->airline = airline;
    this->seatPref = seatPref;
}

char FlightBooking::getSeatPref() const
{
    return seatPref;
}

string FlightBooking::showDetails(){
    string s(1,seatPref);
    return s;
}

