/*
 * Praktikum 3
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

void RentalCarReservation::set(string pickupLocation, string returnLocation, string company){

    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
}

