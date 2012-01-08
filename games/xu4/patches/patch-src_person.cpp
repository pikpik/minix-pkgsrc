$NetBSD$

Add missing header.

--- src/person.cpp.orig	2005-09-21 06:42:01.000000000 +0000
+++ src/person.cpp
@@ -28,6 +28,7 @@
 #include "u4file.h"
 #include "utils.h"
 #include "script.h"
+#include <string.h>
 
 using std::string;
 using std::vector;
