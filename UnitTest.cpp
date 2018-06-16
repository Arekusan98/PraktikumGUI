/*#include "UnitTest.h"
#include "travelagency.h"
#include "hotelbooking.h"

void Test::readFile_CorrectNumberOfBookings(){
    TravelAgency travel;
    travel.readFile();
    QCOMPARE(travel.getAllBookings().size(), 87);
}

void Test::readFile_CorrectProportionOfSmokers()
{
    int smoker = 0;
    int total = 0;


    TravelAgency travel;
    travel.readFile();
    vector<Booking*> TestBookings = travel.getAllBookings();
    for(int i = 0; i < TestBookings.size(); i++){
        if(dynamic_cast<HotelBooking*>(TestBookings.at(i)) != nullptr){
            if(TestBookings.at(i)->showDetails() == "Raucher"){
                smoker++;
            }
            total++;
        }
    }

    int percent = (smoker/total) * 100;

    QCOMPARE(percent, 68);

}
*/
