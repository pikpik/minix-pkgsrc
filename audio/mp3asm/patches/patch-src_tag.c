$NetBSD$

--- src/tag.c.orig	2012-08-10 13:07:07.000000000 +0000
+++ src/tag.c
@@ -25,6 +25,7 @@
 #include "utils.h"
 #include "frame.h"
 
+#define log logfile
 
 /* utils.c */
 extern void *tmalloc (size_t size);
