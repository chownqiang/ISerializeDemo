#include "Teacher.h"
#include "Student.h"
#include "../SerializedTools/SerializedTool.h"
#include "../SerializedTools/RegistorType.h"
#include "../SerializedTools/JsonSerializeType.h"

Teacher::Teacher()
{
    st = new Student();
    //st->RegistorTool();
}

void Teacher::RegistorTool()
{
    RegistorType t(GETNAME(Teacher));

    t.RegistorField(this,GETNAME(st),&st,JsonSerializedTypePIJsonModel().GetId());
    t.RegistorField(this,GETNAME(st2),&st2,JsonSerializedTypeIJsonModel().GetId());
    t.RegistorField(this,GETNAME(age),&age,JsonSerializedTypeInt().GetId());
    t.RegistorField(this,GETNAME(name),&name,JsonSerializedTypeQString().GetId());
    SerializedTool::Instance()->Registor(t);
}

QString Teacher::EncodeToJson()
{
    return  SerializedTool::Instance()->Serialized(this,GETNAME(Teacher));
}

void Teacher::DecodeFromJson(QString json)
{
    SerializedTool::Instance()->Deserialized(this,GETNAME(Teacher),json);
}
