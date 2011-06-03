$NetBSD$

* require <cstring> header for strlen(3) and strncmp(3).

--- src/param.cpp.orig	2005-09-05 14:50:59.000000000 +0000
+++ src/param.cpp
@@ -24,6 +24,7 @@
 #include <fstream>
 #include <strstream>
 #include <cstdio>
+#include <cstring>
 #include "param.h"
 #include "common.h"
 
