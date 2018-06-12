/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <vector>
#include "QDate"
using namespace std;
class Booking
{
public:
    Booking();
    void set(long id, double price, string fromDate, string toDate, long travelId);
    long getId();
    double getPrice();

    long getTravelId();

    QDate getFromDate();

    QDate getToDate();
    virtual string showDetails() = 0;
    virtual vector<string> getInfo() = 0;
protected:
    long id;
    double price;
    long travelId;
    QDate fromDate;
    QDate toDate;
};

#endif // BOOKING_H
