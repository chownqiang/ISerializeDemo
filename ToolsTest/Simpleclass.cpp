#include "Simpleclass.h"

#include <SerializedTool.h>

SimpleClass::SimpleClass()
{

}

void SimpleClass::RegistorTool()
{
    RegistorType type = RegistorType(GETNAME(SimpleClass));
    type.RegistorField(this,GETNAME(p), &p, JsonSerializedTypeQVector_int("qvector_int").GetId());

    SerializedTool::Instance()->Registor(type);
}

QString SimpleClass::EncodeToJson()
{
    return SerializedTool::Instance()->Serialized(this, GETNAME(SimpleClass));
}

void SimpleClass::DecodeFromJson(QString json)
{
    SerializedTool::Instance()->Deserialized(this, GETNAME(SimpleClass), json);
}
