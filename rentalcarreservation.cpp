/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "rentalcarreservation.h"


RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, long travelId, string pickupLocation, string returnLocation, string company, string insuranceType){

    this->id = id;
    this->price = price;
    this->fromDate.setDate(stoi(fromDate.substr(0,4)), stoi(fromDate.substr(4,2)), stoi(fromDate.substr(6,2)));

    this->toDate.setDate(stoi(toDate.substr(0,4)), stoi(toDate.substr(4,2)), stoi(toDate.substr(6,2)));
    this->travelId = travelId;
    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
    this->insuranceType = insuranceType;
}
string RentalCarReservation::showDetails(){
    return insuranceType;
}

string RentalCarReservation::getPickupLocation(){
    return this->pickupLocation;
}
string RentalCarReservation::getReturnLocation(){
    return this->returnLocation;
}
string RentalCarReservation::getCompany(){
    return this->company;
}

vector<string> RentalCarReservation::getInfo()
{
    vector<string> info;
    info.push_back("R");
    info.push_back(this->pickupLocation);
    info.push_back(this->returnLocation);
    info.push_back(this->company);
    return info;
}
