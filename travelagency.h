/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include "booking.h"
#include "travel.h"
#include "customer.h"

using namespace std;

class TravelAgency
{
public:
    TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    void setupBookingTravelCustomer(long bookingId, double price, long travelId, string fromDate, string toDate, long customerId, string customerName);

    vector<Booking *> getAllBookings();

    vector<Customer *> getAllCustomers();

    vector<Travel *> getAllTravels();

private:
    vector<Booking *> allBookings;
    vector<Customer*>allCustomers;
    vector<Travel*>allTravels;
};

#endif // TRAVELAGENCY_H
