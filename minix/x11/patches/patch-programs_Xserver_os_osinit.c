$NetBSD$

--- programs/Xserver/os/osinit.c.orig	Sun Aug  1 11:44:34 2010
+++ programs/Xserver/os/osinit.c
@@ -73,7 +73,7 @@ SOFTWARE.
 #include <sys/resource.h>
 #endif
 
-#ifdef MINIX3
+#ifdef __minix
 #define setpgid(a,b)
 #endif
 
@@ -142,7 +142,7 @@ OsInit(void)
 		dup2 (fileno (err), 2);
 		fclose (err);
 	    }
-#if defined(SYSV) || defined(SVR4) || defined(__UNIXOS2__) || defined(WIN32) || defined(__CYGWIN__) || defined(MINIX3)
+#if defined(SYSV) || defined(SVR4) || defined(__UNIXOS2__) || defined(WIN32) || defined(__CYGWIN__) || defined(__minix)
 	    {
 	    static char buf[BUFSIZ];
 	    setvbuf (stderr, buf, _IOLBF, BUFSIZ);
@@ -162,7 +162,7 @@ OsInit(void)
 #endif
 #endif
 
-#ifndef _MINIX
+#ifndef __minix
 #ifdef RLIMIT_DATA
 	if (limitDataSpace >= 0)
 	{
