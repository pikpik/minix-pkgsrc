$NetBSD$

Add missing header.

--- src/intro.cpp.orig	2005-10-03 05:57:31.000000000 +0000
+++ src/intro.cpp
@@ -24,6 +24,7 @@
 #include "tilemap.h"
 #include "u4file.h"
 #include "utils.h"
+#include <string.h>
 
 using namespace std;
 
