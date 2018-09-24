#ifndef IJSONMODEL_H
#define IJSONMODEL_H

#include<QString>

class ISerializedModel
{
public:
     virtual void  RegistorTool() = 0;
};

class IJsonModel : public ISerializedModel
{
public:
    virtual QString EncodeToJson() = 0;
    virtual void DecodeFromJson(QString json) = 0;
};


#endif
