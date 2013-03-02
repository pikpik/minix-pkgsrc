$NetBSD$

--- core/libs/database/databaseserverstarter.cpp.orig	2013-02-28 09:52:35.000000000 +0000
+++ core/libs/database/databaseserverstarter.cpp
@@ -82,7 +82,7 @@ public:
     }
 };
 
-DatabaseServerStarter::DatabaseServerStarter(QObject* parent=0)
+DatabaseServerStarter::DatabaseServerStarter(QObject* parent)
     : QObject(parent)
 {
 }
