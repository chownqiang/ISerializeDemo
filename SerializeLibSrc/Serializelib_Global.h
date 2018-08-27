#ifndef SERIALIZELIB_GLOBAL_H
#define SERIALIZELIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>
#include "QJsonValue"
#include "QJsonObject"
#include "QJsonDocument"
#include "QDebug"
#include "QException"

#if defined(ABC_LIBRARY)
#  define ABCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ABCSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SERIALIZELIB_GLOBAL_H
