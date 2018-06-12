/*
 * Praktikum 4
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
    HotelBooking(long id, double price, string fromDate, string toDate, long travelId, string hotel, string town, bool smoke);
    virtual string showDetails();
    string getHotel();
    string getTown();
    vector<string> getInfo();
private:
    string hotel;
    string town;
    bool smoke;
};

#endif // HOTELBOOKING_H
