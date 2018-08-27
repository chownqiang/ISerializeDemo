#include "Position.h"


void Position::InitSerializeKeys()
{
    SetKeyData( "id",&this->id,  SerializeDataType::QString_type);
    SetKeyData( "value",&this->value, SerializeDataType::double_type);
    SetKeyData( "username",&this->username, SerializeDataType::QString_type);
    SetKeyData( "surname",&this->surname, SerializeDataType::QString_type);
}
