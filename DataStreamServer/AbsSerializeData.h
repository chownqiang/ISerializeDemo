#ifndef ABSSERIALIZEDATA_H
#define ABSSERIALIZEDATA_H

#include "QString"
#include "SerializeDataType.h"
#include "ISerializeTool.h"

class AbsSerializeData
{
    // function
public:
    AbsSerializeData();

    QString SerializeToString();
    void DeserializeByString(QString strData);

    QList<SerializeData>* GetKeys();

protected:
    //use SetKeyData to SetSerializeKeys
    virtual void InitSerializeKeys() =0;

protected:
    void SetKeyData(QString key,void* keyPointer,SerializeDataType type);

private:
    void Init();

    // field
private:
    QList<SerializeData>* Keys;
    ISerializeTool *serializeTool;
    bool setKeys=false;
};

#endif // ABSSERIALIZEDATA_H
