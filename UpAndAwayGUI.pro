#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T15:09:17
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UpAndAwayGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    booking.cpp \
    customer.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    rentalcarreservation.cpp \
    travel.cpp \
    travelagency.cpp \
    mainwindow.cpp \
    travelagencytest.cpp \
    traveltest.cpp

HEADERS += \
        mainwindow.h \
    booking.h \
    customer.h \
    flightbooking.h \
    hotelbooking.h \
    rentalcarreservation.h \
    travel.h \
    travelagency.h \
    travelagencytest.h \
    traveltest.h \
    node.h \
    list.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    bookings.txt
