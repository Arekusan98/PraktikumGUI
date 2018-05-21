/*
 * Praktikum 2
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <vector>
using namespace std;
class Booking
{
public:
    Booking();
    void set(long id, double price, string fromDate, string toDate, long travelId);
    long getId();
    double getPrice();

    long getTravelId();

protected:
    long id;
    double price;
    long travelId;
    string fromDate;
    string toDate;
};

#endif // BOOKING_H
