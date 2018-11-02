#ifndef SERIALIZEDDATA_H
#define SERIALIZEDDATA_H

#include "serializedtools_global.h"
#include "ISerializedType.h"
#include <QMap>
#include <getopt.h>
#include <functional>
#include <ctype.h>

struct SerializedData
{
public:
    void* getOffset(const void* data);
    QString key;
    int64_t offset;
    QString typeId;
    std::function<QString(void* data)> func;
    QString nextkey;
};



#endif // SERIALIZEDDATA_H
