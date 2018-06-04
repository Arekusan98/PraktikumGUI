/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

void HotelBooking::set(string hotel, string town, bool smoke){

    this->hotel = hotel;
    this->town = town;
    this->smoke = smoke;
}
string HotelBooking::showDetails(){
    if (smoke){
        return "kurwa";
    }

    else {
        return "!kurwa";
    }

}

