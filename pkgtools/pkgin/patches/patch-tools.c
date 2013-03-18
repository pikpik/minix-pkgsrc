--- tools.c.orig	Sat Aug  4 14:23:46 2012
+++ tools.c	Mon Mar 18 02:44:37 2013
@@ -245,7 +245,7 @@
 	if (uname(&un) < 0)
 		return NULL;
 
-#ifdef _MINIX
+#ifdef __minix
 	asprintf(&ret, "%s.%s", un.release, un.version);
 #else
 	XSTRDUP(ret, un.release);
