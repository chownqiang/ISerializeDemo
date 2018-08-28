#include "Classroom.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

Classroom::Classroom()
{
    this->t = new Teacher();
}

void Classroom::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, new DefaultJsonSerialize_QString());
    this->SetKeyData("t", &this->t,new DefaultJsonSerialize_PAbsSerializeData());
    this->SetKeyData("s", &this->s,new DefaultJsonSerialize_AbsSerializeData());
}
