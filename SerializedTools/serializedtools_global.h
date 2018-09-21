#ifndef SERIALIZEDTOOLS_GLOBAL_H
#define SERIALIZEDTOOLS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>
#include "QJsonValue"
#include "QJsonObject"
#include "QJsonDocument"
#include "QDebug"
#include "QException"


#if defined(SERIALIZEDTOOLS_LIBRARY)
#  define SERIALIZEDTOOLSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SERIALIZEDTOOLSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SERIALIZEDTOOLS_GLOBAL_H
