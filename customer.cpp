/*
 * Praktikum 3
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/
#include "customer.h"

Customer::Customer()
{

}
void Customer::addTravel(Travel *travel){
        this->travelList.push_back(travel);
}
void Customer::set(long id, string name){
    this->id=id;
    this->name=name;
}
long Customer::getId(){
    return this->id;
}
vector<Travel*> Customer::getTravelList(){
    return this->travelList;
}
string Customer::getName(){
    return this->name;
}
