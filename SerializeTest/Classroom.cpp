#include "Classroom.h"

Classroom::Classroom()
{
    this->t = new Teacher();
}

void Classroom::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, SerializeDataType::QString_type);
    this->SetKeyData("t", &this->t,SerializeDataType::AbsSerializeData_ptype);
    this->SetKeyData("s", &this->s, SerializeDataType::AbsSerializeData_type);
}
