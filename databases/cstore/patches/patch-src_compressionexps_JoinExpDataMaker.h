$NetBSD$

Add missing header.

--- src/compressionexps/JoinExpDataMaker.h.orig	2006-10-17 19:36:03.000000000 +0000
+++ src/compressionexps/JoinExpDataMaker.h
@@ -61,7 +61,7 @@
 #include "../AM/PagePlacer.h"
 #include <ctime>
 #include "../UnitTests/UnitTest.h"
-#include <fstream.h>
+#include <fstream>
 
 class JoinExpDataMaker : public UnitTest
 {
