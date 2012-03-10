$NetBSD$

Fix build with gcc 4.6

--- dbxml/src/dbxml/dataItem/Join.cpp.orig	2009-12-22 13:17:00.000000000 +0000
+++ dbxml-2.5.16/dbxml/src/dbxml/dataItem/Join.cpp
@@ -5,6 +5,7 @@
 //
 //
 
+#include <stddef.h>
 #include "Join.hpp"
 #include "DbXmlNodeImpl.hpp"
 
