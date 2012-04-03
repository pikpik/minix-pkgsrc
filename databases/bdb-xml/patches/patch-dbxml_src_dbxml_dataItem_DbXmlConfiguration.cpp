$NetBSD$

Fix build with gcc 4.6

--- src/dbxml/dataItem/DbXmlConfiguration.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ src/dbxml/dataItem/DbXmlConfiguration.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "DbXmlConfiguration.hpp"
 #include "DbXmlFactoryImpl.hpp"
 #include "DbXmlSequenceBuilder.hpp"
