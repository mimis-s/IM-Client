#-------------------------------------------------
#
# Project created by QtCreator 2022-11-17T16:27:42
#
#-------------------------------------------------

QT       += core gui
QT       += network
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
    common/commonproto/errors.pb.cc \
    common/commonproto/home_account.pb.cc \
    common/commonproto/home_chat.pb.cc \
    common/commonproto/home_friends.pb.cc \
    common/commonproto/home_relay.pb.cc \
    common/log/im_log.cpp \
    common/socket/socket.cpp \
        main.cpp \
        im_client.cpp \
    src/login/login.cpp \
    src/register/register.cpp

HEADERS += \
    common/commonproto/errors.pb.h \
    common/commonproto/home_account.pb.h \
    common/commonproto/home_chat.pb.h \
    common/commonproto/home_friends.pb.h \
    common/commonproto/home_relay.pb.h \
    common/log/im_log.h \
    common/socket/socket.h \
    common/crc32/crc32.h \
        im_client.h \
    src/login/login.h \
    src/register/register.h \
    common/define/define.h


FORMS += \
        im_client.ui \
    src/login/login.ui \
    src/register/register.ui

DISTFILES += \
    README.md \
    make_proto.sh

#protobuf lib and include
INCLUDEPATH += /usr/local/protobuf/include
LIBS += /usr/local/protobuf/lib/libprotobuf.a -lpthread
