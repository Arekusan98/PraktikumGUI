
/*
 * Praktikum 2
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "travel.h"

using namespace std;

class Customer
{
public:
    Customer();
    void addTravel(Travel* travel);
    void set(long id, string name);
    long getId();
    vector<Travel*> getTravelList();
    string getName();
private:
    long id;
    string name;
    vector<Travel*> travelList;
};

#endif // CUSTOMER_H
