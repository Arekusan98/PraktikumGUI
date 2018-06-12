/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <string>
#include <vector>
#include "booking.h"
using namespace std;

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(long id, double price, string fromDate, string toDate, long travelId, string pickupLocation, string returnLocation, string company, string insuranceType);
    virtual string showDetails();
    string getPickupLocation();
    string getReturnLocation();
    string getCompany();
    vector<string> getInfo();
private:
    string pickupLocation;
    string returnLocation;
    string company;
    string insuranceType;
};

#endif // RENTALCARRESERVATION_H
