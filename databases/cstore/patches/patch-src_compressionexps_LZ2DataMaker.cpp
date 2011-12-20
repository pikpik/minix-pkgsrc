$NetBSD$

Add missing header.

--- src/compressionexps/LZ2DataMaker.cpp.orig	2006-10-18 06:04:07.000000000 +0000
+++ src/compressionexps/LZ2DataMaker.cpp
@@ -31,7 +31,7 @@
  /**
  */
 #include "LZ2DataMaker.h"
-#include <fstream.h>
+#include <fstream>
 
 LZ2DataMaker::LZ2DataMaker() {
 }
