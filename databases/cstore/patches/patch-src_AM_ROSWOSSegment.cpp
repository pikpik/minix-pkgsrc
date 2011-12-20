$NetBSD$

Add missing header.

--- src/AM/ROSWOSSegment.cpp.orig	2006-10-18 06:05:29.000000000 +0000
+++ src/AM/ROSWOSSegment.cpp
@@ -32,6 +32,7 @@
 #include <fstream>
 #include <sstream>
 #include <strstream>
+#include <stdlib.h>
 
 #include <db_cxx.h>
 
