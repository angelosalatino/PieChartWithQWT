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

LIBS = `pkg-config --libs gtk+-2.0` -lm -lasound -lgsl -lgslcblas

INCLUDEPATH += /usr/local/include \
               /usr/local/Trolltech/Qt-4.8.4/include/ \
               /usr/include/gtk-2.0/ \
               /usr/local/include/gsl \
                /usr/local/qwt-6.0.1/include/ \
               features/ \
                classificatore/ \
                audio/ \
                plot/

QMAKE_CXXFLAGS += -DUNIX -Dlinux -DALSA `pkg-config --cflags gtk+-2.0` -Werror=missing-prototypes -Werror=implicit -Wreturn-type -Wunused -Wunused-parameter -Wuninitialized -O1 -g1 -Wshadow -Xlinker -zmuldefs



LIBS += -L/usr/local/Trolltech/Qt-4.8.4/lib/
LIBS += -L/usr/local/lib \
    -L/usr/local/qwt-6.0.1/lib \
    -lavcodec \
    -lavdevice \
    -lavfilter \
    -lavformat \
    -lavutil \
    -lswresample \
    -lswscale \
    -lqwt



SOURCES += main.cpp\
    PieMarker.cpp \
    PiePlot.cpp

HEADERS  += \
    PiePlot.h \
    PieMarker.h

FORMS    += mainwindow.ui
