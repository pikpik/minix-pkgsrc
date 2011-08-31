$NetBSD$

--- src/fdlist.c.orig	Wed Feb 28 04:17:46 2007
+++ src/fdlist.c
@@ -83,11 +83,13 @@ recalc_fdlimit(void *unused)
   int fdmax;
   struct rlimit limit;
 
+#ifndef __minix
   if (!getrlimit(RLIMIT_FD_MAX, &limit))
   {
     limit.rlim_cur = limit.rlim_max;
     setrlimit(RLIMIT_FD_MAX, &limit);
   }
+#endif
 
   fdmax = getdtablesize();
 
