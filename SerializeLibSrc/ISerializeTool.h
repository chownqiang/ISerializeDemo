#ifndef ISERIALIZETOOL_H
#define ISERIALIZETOOL_H


class AbsSerializeData;
#include <QString>

class ISerializeTool
{
public:
    virtual QString Serialization(AbsSerializeData* data)=0;
    virtual void Deserialization(AbsSerializeData* data, QString strData)=0;
};

#endif // ISERIALIZETOOL_H
