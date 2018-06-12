/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "flightbooking.h"

FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, long travelId, string fromDest, string toDest, string airline, char seatPref){

    this->id = id;
    this->price = price;
    this->fromDate.setDate(stoi(fromDate.substr(0,4)), stoi(fromDate.substr(4,2)), stoi(fromDate.substr(6,2)));

    this->toDate.setDate(stoi(toDate.substr(0,4)), stoi(toDate.substr(4,2)), stoi(toDate.substr(6,2)));
    this->travelId = travelId;
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

string FlightBooking::getFromDest(){
    return this->fromDest;
}
string FlightBooking::getToDest(){
    return this->toDest;
}
string FlightBooking::getAirline(){
    return this->airline;
}

vector<string> FlightBooking::getInfo()
{
    vector<string> info;
    info.push_back("F");
    info.push_back(this->fromDest);
    info.push_back(this->toDest);
    info.push_back(this->airline);
    return info;
}

