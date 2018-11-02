#include "Classroom.h"

#include <JsonSerializedType.h>
#include "SerializedTool.h"
#include <RegistorType.h>

ClassRoom::ClassRoom()
{

}

void ClassRoom::RegistorTool()
{
    RegistorType type = RegistorType(GETNAME(Student));
    type.RegistorField(this, GETNAME(teacher), &teacher, JsonSerializedTypePIJsonModel().GetId());
    type.RegistorField(this, GETNAME(stus), &stus, JsonSerializedTypePIJsonModel().GetId());

    SerializedTool::Instance()->Registor(type);
}

QString ClassRoom::EncodeToJson()
{
    //TODO
}

void ClassRoom::DecodeFromJson(QString json)
{
    //TODO
}
