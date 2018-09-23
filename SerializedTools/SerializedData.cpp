#include "SerializedData.h"

void *SerializedData::getOffset(const void *data)
{
    return (void*)((char*)data + offset);
}
