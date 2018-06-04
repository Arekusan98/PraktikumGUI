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
    RentalCarReservation();
    void set(string pickupLocation, string returnLocation, string company, string insuranceType);
    virtual string showDetails();
private:
    string pickupLocation;
    string returnLocation;
    string company;
    string insuranceType;
};

#endif // RENTALCARRESERVATION_H
