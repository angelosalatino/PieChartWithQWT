#-------------------------------------------------
#
# Project created by QtCreator 2014-06-03T10:32:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qwt

TARGET = PieChart
TEMPLATE = app

INCLUDEPATH += /usr/local/qwt-6.0.1/include/

LIBS += -L/usr/local/qwt-6.0.1/lib -lqwt



SOURCES += main.cpp\
    PieMarker.cpp \
    PiePlot.cpp

HEADERS  += \
    PiePlot.h \
    PieMarker.h

FORMS    += mainwindow.ui
