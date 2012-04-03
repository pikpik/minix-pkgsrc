$NetBSD$

--- history.h.orig	1999-05-20 03:53:59.000000000 +0000
+++ history.h
@@ -4,6 +4,7 @@
 #ifdef DMALLOC
 #include <dmalloc.h>
 #endif
+#include <string.h>
 
 class tcommand {
 public:
