#ifndef TRAVELTEST_H
#define TRAVELTEST_H
#include <QtTest/QTest>
#include "travel.h"
#include "travelagency.h"

class TravelTest : public QObject
{
    Q_OBJECT
private slots:
    void checkNeedlessHotels();
    void checkRoundTrip();
    void checkMissingHotel();
public:
    TravelTest();
    TravelAgency CreateUut();
};

#endif // TRAVELTEST_H
