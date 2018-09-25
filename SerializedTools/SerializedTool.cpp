#include "SerializedTool.h"
#include "JsonSerialized.h"
#include "JsonSerializedType.h"


SerializedTool* SerializedTool::Instance()
{
    static SerializedTool* stool = nullptr;
    if(stool)
        return stool;

    stool = new SerializedTool();

    return stool;
}


void SerializedTool::Registor(RegistorType type)
{
    if(container.keys().contains(type.typeName))
        return;

    container.insert(type.typeName,type.GetKeys());
}

QString SerializedTool::Serialized(ISerializedModel *data, QString typeName)
{
   if(!this->container.keys().contains(typeName))
       data->RegistorTool();

    if(!this->container.keys().contains(typeName))
    {
        qDebug() << "find not typeName, please use functional SerializedTool::Registor :" << typeName ;
        return "";
    }

    return this->itool->Serialization(data,this->container[typeName]);
}

void SerializedTool::Deserialized(ISerializedModel *data, QString typeName, QString dataStr)
{
    if(!this->container.keys().contains(typeName))
        data->RegistorTool();

    if(!this->container.keys().contains(typeName))
    {
        qDebug() << "find not typeName, please use functional SerializedTool::Registor :" << typeName ;
        return ;
    }

    this->itool->Deserialization(data, this->container[typeName], dataStr);
}

SerializedTool::SerializedTool()
{
    this->itool = JsonSerialized::Instance();
}

