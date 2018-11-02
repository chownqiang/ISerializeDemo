#include "Student.h"
#include "SerializedTool.h"
#include "RegistorType.h"
#include "JsonSerializeType.h"

Student::Student()
{

}

void Student::RegistorTool()
{
    RegistorType type = RegistorType(GETNAME(Student));
    type.RegistorField(this, GETNAME(age), &age, JsonSerializedTypeInt().GetId());
    type.RegistorField(this, GETNAME(name), &name, JsonSerializedTypeQString().GetId());

    SerializedTool::Instance()->Registor(type);
}

QString Student::EncodeToJson()
{
    return SerializedTool::Instance()->Serialized(this, GETNAME(Student));
}

void Student::DecodeFromJson(QString json)
{
    SerializedTool::Instance()->Deserialized(this, GETNAME(Student), json);
}
