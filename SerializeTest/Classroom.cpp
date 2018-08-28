#include "Classroom.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

Classroom::Classroom()
{
    this->t = new Teacher();
}

void Classroom::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("t", &this->t, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_PAbsSerializeData()));
    this->SetKeyData("s", &this->s, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_AbsSerializeData()));
}
