#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T14:27:08
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bota2
TEMPLATE = app


SOURCES += main.cpp\
        bota2.cpp \
    addteam.cpp \
    addmatch.cpp

HEADERS  += bota2.h \
    addteam.h \
    addmatch.h

FORMS    += bota2.ui \
    addteam.ui \
    addmatch.ui
