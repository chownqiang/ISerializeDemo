#ifndef ISERIALIZETYPE_H
#define ISERIALIZETYPE_H

class SerializeData;
#include "QString"

class ISerializeType
{
public:
    virtual QString GetTypename()=0;
    virtual void* Serialization(const SerializeData* data)=0;
    virtual void Deserialization(const SerializeData* data,const void* value)=0;
};


#endif // ISERIALIZETYPE_H
