$NetBSD$

Add __NetBSD__ support

--- carp.c.orig	2012-05-04 22:27:57.000000000 +0000
+++ carp.c
@@ -102,7 +102,7 @@ static char proggy[MAXPATHLEN];
 
 const char *thisprogname(void)
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || (__NetBSD__)
 	return getprogname();
 #elif defined(__APPLE__)
 	return getprogname();
