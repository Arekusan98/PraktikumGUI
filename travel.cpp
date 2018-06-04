/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "travel.h"

Travel::Travel()
{

}
void Travel::addBooking(Booking *booking){
this->travelBookings.push_back(booking);
}

void Travel::set(long id, long customerId){
    this->customerId=customerId;
    this->id=id;
}

long Travel::getId(){
    return this->id;
}

vector<Booking*> Travel::getTravelBookings(){
    return this->travelBookings;
}
long Travel::getCustomerId(){
    return this->customerId;
}
