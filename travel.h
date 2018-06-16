/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef TRAVEL_H
#define TRAVEL_H
#include <vector>
#include "booking.h"
class Travel
{
public:
    Travel();
    void addBooking(Booking* booking);
    void set(long id, long customerId);
    long getId();
    vector<Booking*> getTravelBookings();
    long getCustomerId();
    bool checkRoundTrip();
    bool checkNeedlessHotel();
    bool checkMissingHotel();
    Booking *findFirstBooking();
    Booking *findLastBooking();
private:
    long id;
    long customerId;
    vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
