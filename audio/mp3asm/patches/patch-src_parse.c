$NetBSD$

--- src/parse.c.orig	2012-08-10 13:06:54.000000000 +0000
+++ src/parse.c
@@ -26,6 +26,8 @@
 #include "parse.h"
 #include "utils.h"
 
+#define log logfile
+
 /* mp3asm.c */
 extern void new_input (void);
 
