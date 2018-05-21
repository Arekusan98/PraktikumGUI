/*
 * Praktikum 2
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
    void set(string fromDest, string toDest, string airline);
private:
    string fromDest;
    string toDest;
    string airline;
};

#endif // FLIGHTBOOKING_H
