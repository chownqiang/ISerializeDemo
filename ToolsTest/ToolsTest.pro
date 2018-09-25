#-------------------------------------------------
#
# Project created by QtCreator 2018-09-21T14:02:59
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_toolstest
CONFIG   += console
CONFIG   -= app_bundle

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
    tst_toolstest.cpp \
    ../SerializedTools/JsonSerialized.cpp \
    ../SerializedTools/JsonSerializedType.cpp \
    ../SerializedTools/RegistorType.cpp \
    ../SerializedTools/SerializedData.cpp \
    ../SerializedTools/SerializedTool.cpp \
    Student.cpp \
    Teacher.cpp

HEADERS += \
    ../SerializedTools/ISerialized.h \
    ../SerializedTools/ISerializedModel.h \
    ../SerializedTools/ISerializedType.h \
    ../SerializedTools/JsonSerializedType.h \
    ../SerializedTools/JsonSerialized.h \
    ../SerializedTools/RegistorType.h \
    ../SerializedTools/SerializedData.h \
    ../SerializedTools/SerializedTool.h \
    ../SerializedTools/serializedtools_global.h \
    Student.h \
    Teacher.h
