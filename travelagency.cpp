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
fstream bookingFile;
bookingFile.open("C:/repos/Praktikum3_GUI/UpAndAwayGUI/bookings.txt");
int amountFlight = 0;
int amountRental = 0;
int amountHotel = 0;
while(!bookingFile.eof()){
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
    for (int i = 0; i<7;i++){
        getline(lineStream, text, '|');
        input.push_back(text);
       }
    long bookingId = stol(input.at(0));
    double price = stod(input.at(1));
    string fromDate = input.at(2);
    string toDate = input.at(3);
    long travelId = stol(input.at(4));
    long customerId = stol(input.at(5));
    string customerName = input.at(6);

//check type and then react accordingly
    if(!type.compare("F")){

        getline(lineStream, text, '|');
        string fromDest = text;
        getline(lineStream, text, '|');
        string toDest = text;
        getline(lineStream, text, '|');
        string airline = text;
        getline(lineStream, text, '|');
        string seatPref = text;

        FlightBooking* flight = new FlightBooking();
        flight->Booking::set(bookingId, price, fromDate, toDate, travelId);
        flight->set(fromDest, toDest, airline, seatPref.at(0));
        this->setupBookingTravelCustomer(bookingId, price, travelId, fromDate, toDate, customerId, customerName);
        amountFlight++;
    }

    if(!type.compare("R")){
        getline(lineStream, text, '|');
        string pickupLocation = text;
        getline(lineStream, text, '|');
        string returnLocation = text;
        getline(lineStream, text, '|');
        string company = text;
        getline(lineStream, text, '|');
        string insuranceType = text;


        RentalCarReservation* rental = new RentalCarReservation();
        rental->Booking::set(bookingId, price, fromDate, toDate, travelId);
        rental->set(pickupLocation, returnLocation, company, insuranceType);
        this->setupBookingTravelCustomer(bookingId, price, travelId, fromDate, toDate, customerId, customerName);
        amountRental++;
      }

    if(!type.compare("H")){
        getline(lineStream, text, '|');
        string hotel = text;
        getline(lineStream, text, '|');
        string town = text;
        getline(lineStream, text, '|');
        string smoke = text;
        HotelBooking* hotelbooking = new HotelBooking();
        hotelbooking->Booking::set(bookingId, price, fromDate, toDate, travelId);
        hotelbooking->set(hotel, town, stoi(smoke));
        this->setupBookingTravelCustomer(bookingId, price, travelId, fromDate, toDate, customerId, customerName);
        amountHotel++;
      }
   }
bookingFile.close();
/*
cout << "Anzahl Bookings: "<< this->allBookings.size() << endl;
cout << "Anzahl Customers: "<< this->allCustomers.size() << endl;
cout << "Anzahl Travels: "<< this->allTravels.size()<< endl;
*/}


Booking* TravelAgency::findBooking(long id){
    for(int i = 0; i < allBookings.size(); i++){
        if(allBookings.at(i)->getId() == id){
            return allBookings.at(i);
        }
    }
    return NULL;
}
Customer* TravelAgency::findCustomer(long id){
    for(int i = 0; i < allCustomers.size(); i++){
        if(allCustomers.at(i)->getId() == id){
            return allCustomers.at(i);
        }
    }
    return NULL;
}
Travel* TravelAgency::findTravel(long id){
    for(int i = 0; i < allTravels.size(); i++){
        if(allTravels.at(i)->getId() == id){
            return allTravels.at(i);
        }
    }
    return NULL;
}

void TravelAgency::setupBookingTravelCustomer(long bookingId, double price, long travelId, string fromDate, string toDate, long customerId, string customerName){
    Booking* booking;

    if(!this->findBooking(bookingId)){
        booking->set(bookingId, price, fromDate, toDate, travelId );
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

vector<Booking *> TravelAgency::getAllBookings()
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

