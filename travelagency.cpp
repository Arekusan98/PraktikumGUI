/*
 * Praktikum 4
 *
 * Alexander Manger 754969
 * Maciej Krzyszton 756037
 *
*/

#include "travelagency.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "flightbooking.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include <array>
using namespace std;

TravelAgency::TravelAgency()
{

}
void TravelAgency::readFile(){
int zeile = 0;
fstream bookingFile;
bookingFile.open("C:/repos/Praktikum3_GUI/UpAndAwayGUI/bookings.txt");
int amountFlight = 0;
int amountRental = 0;
int amountHotel = 0;
while(!bookingFile.eof()){
    zeile++;
//declaring Variables
    vector<string>input;
    string text;
//get whole line
    getline(bookingFile, text);
    stringstream lineStream;
    lineStream << text;
//get type of booking
    getline(lineStream, text, '|');
    string type = text;
//get first information and assign to variables

    for (unsigned int i = 0; i<7;i++){
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        input.push_back(text);
       }
    long bookingId;
    double price;
    string fromDate;
    string toDate;
    long travelId;
    long customerId;
    string customerName;
    try{
    bookingId = stol(input.at(0));
    price = stod(input.at(1));
    fromDate = input.at(2);
    toDate = input.at(3);
    travelId = stol(input.at(4));
    customerId = stol(input.at(5));
    customerName = input.at(6);
    }catch(exception e){
       throw runtime_error("Es gab einen Fehler in Zeile " + to_string(zeile));
    }
    //check type and then react accordingly
    if(!type.compare("F")){

        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string fromDest = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string toDest = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string airline = text;
        getline(lineStream, text, '|');        
        checkForMissingAttribute(text, zeile);
        string seatPref = text;



        Booking* booking = nullptr;
        booking = new FlightBooking(bookingId, price, fromDate, toDate, travelId, fromDest, toDest, airline, seatPref.at(0));
        setupBookingTravelCustomer(bookingId, booking, travelId, customerId, customerName);
        amountFlight++;
    }

    if(!type.compare("R")){
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string pickupLocation = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string returnLocation = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string company = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string insuranceType = text;
        Booking* booking = nullptr;
        booking = new RentalCarReservation(bookingId, price, fromDate, toDate, travelId, pickupLocation, returnLocation, company, insuranceType);
        setupBookingTravelCustomer(bookingId, booking, travelId, customerId, customerName);
        amountRental++;
      }

    if(!type.compare("H")){
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string hotel = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string town = text;
        getline(lineStream, text, '|');
        checkForMissingAttribute(text, zeile);
        string smoke = text;
        Booking* booking = nullptr;
        booking = new HotelBooking(bookingId, price, fromDate, toDate, travelId, hotel, town, stoi(smoke));
        setupBookingTravelCustomer(bookingId, booking, travelId, customerId, customerName);
        amountHotel++;
      }
   }
bookingFile.close();
}

void TravelAgency::checkForMissingAttribute(string text, int zeile){
    if(text == "F"|| text == "H" || text == "R"){
        throw runtime_error("Es gab einen Fehler in Zeile " + to_string(zeile));
    }
}

void TravelAgency::reset()
{
    this->allBookings.clear();
    this->allCustomers.clear();
    this->allTravels.clear();
}

Booking* TravelAgency::findBooking(long id){
    for(unsigned int i = 0; i < allBookings.size(); i++){
        if(allBookings.at(i)->getId() == id){
            return allBookings.at(i);
        }
    }
    return NULL;
}
Customer* TravelAgency::findCustomer(long id){
    for(unsigned int i = 0; i < allCustomers.size(); i++){
        if(allCustomers.at(i)->getId() == id){
            return allCustomers.at(i);
        }
    }
    return NULL;
}
Travel* TravelAgency::findTravel(long id){
    for(unsigned int i = 0; i < allTravels.size(); i++){
        if(allTravels.at(i)->getId() == id){
            return allTravels.at(i);
        }
    }
    return NULL;
}

void TravelAgency::setupBookingTravelCustomer(long bookingId, Booking* booking, long travelId, long customerId, string customerName){

    if(!this->findBooking(bookingId)){
        this->allBookings.push_back(booking);
    }else{
        booking = this->findBooking(bookingId);
    }


    Travel* travel = new Travel();
    if(!this->findTravel(travelId)){
        travel->set(travelId, customerId);
        this->allTravels.push_back(travel);
    }else{
        travel = this->findTravel(travelId);
    }
    travel->addBooking(booking);

    Customer* customer = new Customer();

    if(!this->findCustomer(customerId)){
        customer->set(customerId, customerName);
        this->allCustomers.push_back(customer);
    }else{
        customer = this->findCustomer(customerId);
    }
    customer->addTravel(travel);
}

List<Booking *> TravelAgency::getAllBookings()
{
    return allBookings;
}

vector<Customer *> TravelAgency::getAllCustomers()
{
    return allCustomers;
}

vector<Travel *> TravelAgency::getAllTravels()
{
    return allTravels;
}

string TravelAgency::getSizeOfTravelsAsString()
{
    return to_string(allTravels.size());
}
string TravelAgency::getSizeOfBookingsAsString()
{
    return to_string(allBookings.size());
}
string TravelAgency::getSizeOfCustomersAsString()
{
    return to_string(allCustomers.size());
}
vector<string> TravelAgency::getTypeAndInfo(long id){
    vector<string> info = findBooking(id)->getInfo();
    info.push_back(findBooking(id)->showDetails());
    return info;
}

vector<Customer *> TravelAgency::searchFunction(string input)
{

   vector<Customer*>customers;
    for(unsigned int c = 0; c < allCustomers.size(); c++){

        string wort_a = allCustomers.at(c)->getName();
        string wort_b = input;

        int mat[wort_a.length()+1][wort_b.length()+1];
        mat[0][0] = 0;
        for(unsigned int i = 1; i <= wort_a.length(); i++){
            mat[i][0] = i;   //indizes für Zeile
        }
        for(unsigned int j = 1; j <= wort_a.length(); j++){
            mat[0][j] = j; //indizes für Spalte
        }
        vector<int>compareList;
        for(unsigned int i = 1; i <= wort_a.length(); i++){      //jede Zeile durchgehen
            for(unsigned int j = 1; j<= wort_b.length(); j++){   //jede Spalte in einer Zeile durchgehen
                compareList.clear();
                if(wort_a[i-1] == wort_b[j-1]){
                    compareList.push_back(mat[i-1][j-1]);   //diagonal links über aktueller Stelle
                }else{
                    compareList.push_back(mat[i-1][j-1]+1);//diagonal links über aktueller Stelle plus 1
                }
                compareList.push_back(mat[i][j-1]+1);   //über aktueller stelle +1
                compareList.push_back(mat[i-1][j]+1);   //links von aktueller stelle +1

                mat[i][j] = *(min_element(compareList.begin(), compareList.end())); //kleinstes element der liste auf die stelle schreiben
            }
        }

        allCustomers.at(c)->setDistance(mat[wort_a.length()][wort_b.length()]);
        customers.push_back(allCustomers.at(c));

    }
    bool sortActionDone = true;
    while(sortActionDone){
        sortActionDone = false;
        for(unsigned int d = 0; d < customers.size(); d++){
            Customer* temp = customers.at(d);
            Customer* tempPlus1;
            if(d+1<customers.size()){
                tempPlus1 = customers.at(d+1);
            }else{
                tempPlus1 = customers.at(d);
            }
            if(temp->getDistance() > tempPlus1->getDistance()){
                customers.at(d) = tempPlus1;
                customers.at(d+1) = temp;
                sortActionDone = true;
            }
        }
    }

    return customers;
}
