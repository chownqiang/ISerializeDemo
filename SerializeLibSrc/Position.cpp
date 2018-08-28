#include "Position.h"
#include "ISerializeTypeJson.h"


void Position::InitSerializeKeys()
{
    SetKeyData( "id",&this->id, QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    SetKeyData( "value",&this->value,QSharedPointer<ISerializeType>(new DefaultJsonSerialize_Double()));
    SetKeyData( "username",&this->username,QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
    SetKeyData( "surname",&this->surname,QSharedPointer<ISerializeType>(new DefaultJsonSerialize_QString()));
}
