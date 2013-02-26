$NetBSD$

--- readwrite.h.orig	2013-02-25 16:49:34.000000000 +0000
+++ readwrite.h
@@ -1,7 +1,6 @@
 #ifndef READWRITE_H
 #define READWRITE_H
 
-extern int read();
-extern int write();
+#include <unistd.h>
 
 #endif
