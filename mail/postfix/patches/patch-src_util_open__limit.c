$NetBSD$

--- src/util/open_limit.c.orig	Fri Dec 11 18:55:29 1998
+++ src/util/open_limit.c
@@ -51,6 +51,9 @@
 
 int     open_limit(int limit)
 {
+#ifdef MINIX3
+	return 0;
+#else
 #ifdef RLIMIT_NOFILE
     struct rlimit rl;
 #endif
@@ -75,6 +78,7 @@ int     open_limit(int limit)
 
 #ifndef RLIMIT_NOFILE
     return (getdtablesize());
+#endif
 #endif
 }
 
