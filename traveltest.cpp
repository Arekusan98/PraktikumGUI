#include "traveltest.h"

TravelAgency TravelTest::CreateUut(){
    TravelAgency travelAgency;
    travelAgency.readFile();
    return travelAgency;
}

void TravelTest::checkNeedlessHotels()
{
    bool checkNeedlessHotelActual = CreateUut().findTravel(6)->checkNeedlessHotel();
    QCOMPARE(checkNeedlessHotelActual, false);
}

void TravelTest::checkRoundTrip()
{
    bool checkRoundTripActual = CreateUut().findTravel(16)->checkRoundTrip();
    QCOMPARE(checkRoundTripActual, false);
}

void TravelTest::checkMissingHotel()
{
    bool checkMissingHotelActual = CreateUut().findTravel(2)->checkMissingHotel();
    QCOMPARE(checkMissingHotelActual, false);
}

TravelTest::TravelTest(QObject *parent) : QObject(parent)
{

}
