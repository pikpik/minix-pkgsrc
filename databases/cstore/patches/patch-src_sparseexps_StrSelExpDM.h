$NetBSD$

Add missing header.

--- src/sparseexps/StrSelExpDM.h.orig	2006-10-17 19:36:12.000000000 +0000
+++ src/sparseexps/StrSelExpDM.h
@@ -51,7 +51,7 @@
 #include "../AM/PagePlacer.h"
 #include <ctime>
 #include "../UnitTests/UnitTest.h"
-#include <fstream.h>
+#include <fstream>
 
 class StrSelExpDM : public UnitTest
 {
