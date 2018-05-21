/*
 * Praktikum 2
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

void FlightBooking::set(string fromDest, string toDest, string airline){

    this->fromDest = fromDest;
    this->toDest = toDest;
    this->airline = airline;
}

