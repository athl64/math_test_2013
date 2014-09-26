#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T23:35:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = math_test_server_2013
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maththread.cpp \
    mathserver.cpp \
    sharebank.cpp \
    shareid.cpp

HEADERS  += mainwindow.h \
    maththread.h \
    mathserver.h \
    sharebank.h \
    shareid.h

FORMS    += mainwindow.ui
