#-------------------------------------------------
#
# Project created by QtCreator 2018-09-21T12:35:51
#
#-------------------------------------------------

QT       -= gui

TARGET = SerializedTools
TEMPLATE = lib

DEFINES += SERIALIZEDTOOLS_LIBRARY

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
    SerializedTool.cpp \
    JsonSerialized.cpp \
<<<<<<< HEAD
    RegistorType.cpp \
    SerializedData.cpp \
    JsonSerializedType.cpp
=======
    SerializeData.cpp \
    RegistorType.cpp \
    JsonSerializeType.cpp
>>>>>>> e486097683a799512068ceb1ceb4f7d4371a1945

HEADERS += \
    serializedtools_global.h \
    SerializedTool.h \
    ISerialized.h \
    JsonSerialized.h \
<<<<<<< HEAD
    RegistorType.h \
    ISerializedType.h \
    SerializedData.h \
    JsonSerializedType.h
=======
    SerializeData.h \
    RegistorType.h \
    IJsonSerializeType.h \
    JsonSerializeType.h
>>>>>>> e486097683a799512068ceb1ceb4f7d4371a1945

unix {
    target.path = /usr/lib
    INSTALLS += target
}
