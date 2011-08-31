$NetBSD$

--- src/ircd.c.orig	Wed Feb 28 04:17:46 2007
+++ src/ircd.c
@@ -477,7 +477,7 @@ check_pidfile(const char *filename)
 static void
 setup_corefile(void)
 {
-#ifdef HAVE_SYS_RESOURCE_H
+#if defined(HAVE_SYS_RESOURCE_H) && !defined(__minix)
   struct rlimit rlim; /* resource limits */
 
   /* Set corefilesize to maximum */
