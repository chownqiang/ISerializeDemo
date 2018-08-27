#ifndef SERIALIZEDATATYPE_H
#define SERIALIZEDATATYPE_H

#include "Serializelib_Global.h"

enum SerializeDataType
{
    char_type =1,
    short_type =2,
    int_type =3,
    qlonglong_type=4,

    bool_type=5,
    float_type=6,
    double_type=7,
    QString_type=8,

    QByteArray_type=9,
    AbsSerializeData_type=10,
    AbsSerializeData_ptype = 11,

    list_default = 1000,
    list_char_type =1001,
    list_short_type =1002,
    list_int_type =1003,
    list_qlonglong_type=1004,

    list_bool_type=1005,
    list_float_type=1006,
    list_double_type=1007,
    list_QString_type=1008,

    list_QByteArray_type=1009,
    list_AbsSerializeData_type=1010,
    list_AbsSerializeData_ptype = 1011,

};


struct SerializeData
{
public:
    QString key;
    int offset;
    SerializeDataType type;
    char* defaultPointer;
};


#endif // SERIALIZEDATATYPE_H
