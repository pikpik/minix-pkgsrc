$NetBSD$

--- fdm.h.orig	2012-08-23 17:13:57.000000000 +0000
+++ fdm.h
@@ -71,6 +71,10 @@
 
 extern char	*__progname;
 
+#ifndef MAXNAMLEN
+#define MAXNAMLEN NAME_MAX
+#endif
+
 /* Linux compatibility bullshit. */
 #ifndef UID_MAX
 #define UID_MAX UINT_MAX
