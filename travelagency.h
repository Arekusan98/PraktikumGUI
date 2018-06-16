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
    void setupBookingTravelCustomer(long bookingId, Booking *booking, long travelId, long customerId, string customerName);


    vector<Booking *> getAllBookings();

    vector<Customer *> getAllCustomers();

    vector<Travel *> getAllTravels();

    std::string getSizeOfBookingsAsString();
    std::string getSizeOfCustomersAsString();
    std::string getSizeOfTravelsAsString();
    void getDetails(int i);
    vector<string> getTypeAndInfo(long id);
    vector<Customer*> searchFunction(string input);
    void checkForMissingAttribute(string text, int zeile);

    void reset();
private:
    vector<Booking *> allBookings;
    vector<Customer*>allCustomers;
    vector<Travel*>allTravels;
};

#endif // TRAVELAGENCY_H
