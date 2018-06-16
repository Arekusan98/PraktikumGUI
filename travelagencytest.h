#ifndef TRAVELAGENCYTEST_H
#define TRAVELAGENCYTEST_H
#include "travelagency.h"
#include "hotelbooking.h"
#include <QtTest/QTest>

class TravelAgencyTest : public QObject
{
    Q_OBJECT
private slots:
    void readFile_CorrectNumberOfBookings();
    void readFile_CorrectProportionOfSmokers();
public:
    explicit TravelAgencyTest(QObject* parent = 0);
};

#endif // TRAVELAGENCYTEST_H
