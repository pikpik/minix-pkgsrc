$NetBSD$

Add missing header.

--- src/compressionexps/Dict2DataMaker.h.orig	2006-10-17 19:36:03.000000000 +0000
+++ src/compressionexps/Dict2DataMaker.h
@@ -60,7 +60,7 @@
 #include "../AM/PagePlacer.h"
 #include <ctime>
 #include "../UnitTests/UnitTest.h"
-#include <fstream.h>
+#include <fstream>
 
 class Dict2DataMaker : public UnitTest
 {
