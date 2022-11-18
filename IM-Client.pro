#-------------------------------------------------
#
# Project created by QtCreator 2022-11-17T16:27:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IM-Client
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
        im_client.cpp \
    cmd/main.cpp \
    cmd/im_client.cpp

HEADERS += \
        im_client.h \
    cmd/im_client.h

FORMS += \
        im_client.ui \
    cmd/im_client.ui

DISTFILES += \
    cmd/IM-Client
