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
    common/base_widget/chatbox.cpp \
    common/base_widget/chatbubble.cpp \
    common/base_widget/chatheadandbubble.cpp \
    common/base_widget/chatshortframe.cpp \
    common/base_widget/circlelabel.cpp \
    common/commonproto/errors.pb.cc \
    common/commonproto/home_account.pb.cc \
    common/commonproto/home_chat.pb.cc \
    common/commonproto/home_friends.pb.cc \
    common/commonproto/home_message.pb.cc \
    common/commonproto/home_relay.pb.cc \
    common/log/im_log.cpp \
    common/socket/socket.cpp \
        main.cpp \
        im_client.cpp \
    src/chat/chat.cpp \
    src/friends/friendapplybox.cpp \
    src/friends/frienddetails.cpp \
    src/friends/friends.cpp \
    src/global/chathistory.cpp \
    src/global/userinfo.cpp \
    src/home/home.cpp \
    src/login/login.cpp \
    src/register/cutouthead.cpp \
    src/register/register.cpp \
    common/crc32/crc32.cpp

HEADERS += \
    common/base_widget/chatbox.h \
    common/base_widget/chatbubble.h \
    common/base_widget/chatheadandbubble.h \
    common/base_widget/chatshortframe.h \
    common/base_widget/circlelabel.h \
    common/commonproto/errors.pb.h \
    common/commonproto/home_account.pb.h \
    common/commonproto/home_chat.pb.h \
    common/commonproto/home_friends.pb.h \
    common/commonproto/home_message.pb.h \
    common/commonproto/home_relay.pb.h \
    common/log/im_log.h \
    common/socket/socket.h \
    common/crc32/crc32.h \
        im_client.h \
    src/chat/chat.h \
    src/friends/friendapplybox.h \
    src/friends/frienddetails.h \
    src/friends/friends.h \
    src/global/chathistory.h \
    src/global/userinfo.h \
    src/home/home.h \
    src/login/login.h \
    src/register/cutouthead.h \
    src/register/register.h \
    common/define/define.h

FORMS += \
        im_client.ui \
    src/chat/chat.ui \
    src/friends/friendapplybox.ui \
    src/friends/frienddetails.ui \
    src/friends/friends.ui \
    src/home/home.ui \
    src/login/login.ui \
    src/register/cutouthead.ui \
    src/register/register.ui

DISTFILES += \
    README.md \
    make_proto.sh \
    Makefile

#protobuf lib and include
INCLUDEPATH += /usr/local/protobuf/include
LIBS += /usr/local/protobuf/lib/libprotobuf.a -lpthread

RESOURCES += \
    resource/img.qrc
