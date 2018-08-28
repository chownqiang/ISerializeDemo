#include "Student.h"
#include "../SerializeLibSrc/ISerializeTypeJson.h"

void Student::InitSerializeKeys()
{
    this->SetKeyData("name",&this->name, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("age",&this->age,  QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Int()));
    this->SetKeyData("classroom",&this->classroom, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    this->SetKeyData("score",&this->score, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Float()));
}
