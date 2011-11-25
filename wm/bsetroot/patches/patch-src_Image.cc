$NetBSD$

--- src/Image.cc.orig	2011-11-25 15:53:51.000000000 +0000
+++ src/Image.cc
@@ -30,6 +30,7 @@
 #endif // HAVE_STDIO_H
 
 #include <algorithm>
+#include <cstring>
 using std::max;
 using std::min;
 
