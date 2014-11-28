#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T17:34:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tower
TEMPLATE = app


SOURCES += main.cpp\
    colorwheel.cpp \
#    mainwindow.cpp \
    popwindow.cpp

HEADERS  += floatspinbox.h \
    colorwheel.h \
#    mainwindow.h \
    popwindow.h

RESOURCES += rsc_pic/images.qrc
