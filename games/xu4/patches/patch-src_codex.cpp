$NetBSD$

Add missing header.

--- src/codex.cpp.orig	2005-09-06 06:21:15.000000000 +0000
+++ src/codex.cpp
@@ -21,6 +21,7 @@
 #include "u4.h"
 #include "u4file.h"
 #include "utils.h"
+#include <string.h>
 
 using namespace std;
 
