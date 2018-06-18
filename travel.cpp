/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "travel.h"
#include "flightbooking.h"
#include "hotelbooking.h"

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

bool Travel::checkRoundTrip()
{
    if(dynamic_cast<FlightBooking*>(findFirstBooking()) != nullptr)
    {
        FlightBooking* firstFlight = dynamic_cast<FlightBooking*>(findFirstBooking());
        firstFlight->getFromDest();
        if(dynamic_cast<FlightBooking*>(findLastBooking()) != nullptr)
        {
            FlightBooking* lastFlight = dynamic_cast<FlightBooking*>(findLastBooking());
            if(firstFlight == lastFlight)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Booking* Travel::findFirstBooking(){
    vector<long>IDs;
    for(int i = 0; i < travelBookings.size(); i++){
        IDs.push_back(travelBookings.at(i)->getId());
    }
    long firstBooking = *(min_element(IDs.begin(), IDs.end()));
    for(int i = 0; i < travelBookings.size(); i++){
        if(travelBookings.at(i)->getId() == firstBooking){
            return travelBookings.at(i);
        }
    }
}

Booking* Travel::findLastBooking(){
    vector<long>IDs;
    for(int i = 0; i < travelBookings.size(); i++){
        IDs.push_back(travelBookings.at(i)->getId());
    }
    long firstBooking = *(max_element(IDs.begin(), IDs.end()));
    for(int i = 0; i < travelBookings.size(); i++){
        if(travelBookings.at(i)->getId() == firstBooking){
            return travelBookings.at(i);
        }
    }
}

bool Travel::checkNeedlessHotel()
{
    Booking* lastToDateBooking = travelBookings.at(0);
    for(int i = 1; i < travelBookings.size(); i++)
    {
        if(travelBookings.at(i)->getToDate() < lastToDateBooking->getToDate())
        {
            lastToDateBooking = travelBookings.at(i);
        }
    }
    if(dynamic_cast<HotelBooking*>(lastToDateBooking) != nullptr)
    {
        for(int i = 0; i < travelBookings.size(); i++)
        {
            if(lastToDateBooking->getToDate() == travelBookings.at(i)->getToDate())
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool Travel::checkMissingHotel()
{
    if(dynamic_cast<FlightBooking*>(travelBookings.at(0)) != nullptr)
    {
        for(int travelcount = 1; travelcount < travelBookings.size(); travelcount++){
            if(dynamic_cast<HotelBooking*>(travelBookings.at(travelcount)) != nullptr)
            {
                return true;
            }
            else
            {
                if(dynamic_cast<FlightBooking*>(travelBookings.at(travelcount+1)) != nullptr)
                {
                    travelcount++;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
}
