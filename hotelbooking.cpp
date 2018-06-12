/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "hotelbooking.h"


HotelBooking::HotelBooking(long id, double price, string fromDate, string toDate, long travelId, string hotel, string town, bool smoke){

    this->id = id;
    this->price = price;
    this->fromDate.setDate(stoi(fromDate.substr(0,4)), stoi(fromDate.substr(4,2)), stoi(fromDate.substr(6,2)));

    this->toDate.setDate(stoi(toDate.substr(0,4)), stoi(toDate.substr(4,2)), stoi(toDate.substr(6,2)));
    this->travelId = travelId;
    this->hotel = hotel;
    this->town = town;
    this->smoke = smoke;
}
string HotelBooking::showDetails(){
    if (smoke){
        return "Raucher";
    }

    else {
        return "Nichtraucher";
    }

}

string HotelBooking::getHotel()
{
 return this->hotel;
}

string HotelBooking::getTown(){
    return this->town;
}

vector<string> HotelBooking::getInfo()
{
    vector<string> info;
    info.push_back("H");
    info.push_back(hotel);
    info.push_back(town);
    return info;
}

