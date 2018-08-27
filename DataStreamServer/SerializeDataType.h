#ifndef SERIALIZEDATATYPE_H
#define SERIALIZEDATATYPE_H

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
