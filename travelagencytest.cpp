#include "travelagencytest.h"

TravelAgencyTest::TravelAgencyTest(QObject *parent) : QObject(parent)
{

}

void TravelAgencyTest::readFile_CorrectNumberOfBookings(){
    TravelAgency travel;
    travel.readFile();
    QCOMPARE(travel.getAllBookings().size(), 87);
}

void TravelAgencyTest::readFile_CorrectProportionOfSmokers()
{
    double smoker = 0;
    double total = 0;

    TravelAgency travel;
    travel.readFile();
    List<Booking*> TestBookings = travel.getAllBookings();
    for(unsigned int i = 0; i < TestBookings.size(); i++){
        if(dynamic_cast<HotelBooking*>(TestBookings.at(i)) != nullptr){
            if(TestBookings.at(i)->showDetails() == "Raucher"){
                smoker++;
            }
            total++;
        }
    }

    double percent = 100 - ((smoker/total) * 100);
    QCOMPARE(percent, 68);

}

