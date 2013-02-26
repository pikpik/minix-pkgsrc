$NetBSD$

--- log.h.orig	2013-02-25 16:47:13.000000000 +0000
+++ log.h
@@ -1,6 +1,7 @@
 #ifndef LOG_H
 #define LOG_H
 
-extern void log();
+#define log(x,y) my_log(x,y)
+extern void log(char *, char *);
 
 #endif
