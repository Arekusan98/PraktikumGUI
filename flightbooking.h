/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <string>
#include <vector>
#include "booking.h"
using namespace std;

class FlightBooking : public Booking
{
public:
    FlightBooking();
    void set(string fromDest, string toDest, string airline, char seatPref);

    char getSeatPref() const;
    virtual string showDetails();
private:
    string fromDest;
    string toDest;
    string airline;
    char seatPref;
};

#endif // FLIGHTBOOKING_H
