/*
 * Praktikum 3
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <string>
#include <vector>
#include "booking.h"
using namespace std;

class HotelBooking : public Booking
{
public:
    HotelBooking();
    void set(string hotel, string town);
private:
    string hotel;
    string town;
};

#endif // HOTELBOOKING_H
