#include "Position.h"
#include "ISerializeTypeJson.h"


void Position::InitSerializeKeys()
{
    SetKeyData( "id",&this->id, new DefaultJsonSerialize_QString());
    SetKeyData( "value",&this->value,new DefaultJsonSerialize_Double());
    SetKeyData( "username",&this->username,new DefaultJsonSerialize_QString());
    SetKeyData( "surname",&this->surname,new DefaultJsonSerialize_QString());
}
