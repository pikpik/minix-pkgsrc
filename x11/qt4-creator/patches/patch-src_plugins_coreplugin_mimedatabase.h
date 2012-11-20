$NetBSD$

--- src/plugins/coreplugin/mimedatabase.h.orig	2012-11-19 11:22:27.000000000 +0000
+++ src/plugins/coreplugin/mimedatabase.h
@@ -35,13 +35,13 @@
 #include <QtCore/QSharedDataPointer>
 #include <QtCore/QSharedPointer>
 #include <QtCore/QByteArray>
+#include <QtCore/QFileInfo>
 #include <QtCore/QMutex>
 
 QT_BEGIN_NAMESPACE
 class QIODevice;
 class QRegExp;
 class QDebug;
-class QFileInfo;
 QT_END_NAMESPACE
 
 namespace Core {
