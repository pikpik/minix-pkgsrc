$NetBSD$

--- src/util/softsig.c.orig	2012-03-26 23:03:34.000000000 +0000
+++ src/util/softsig.c
@@ -72,7 +72,8 @@ softsig_thread(void *arg)
 
     while (1) {
 	void (*h) (int);
-#if !defined(AFS_DARWIN_ENV) && !defined(AFS_NBSD_ENV)
+#if defined(AFS_DARWIN_ENV) || (defined(AFS_NBSD_ENV) && !defined(AFS_NBSD50_ENV))
+#else
 	int sigw;
 #endif
 
