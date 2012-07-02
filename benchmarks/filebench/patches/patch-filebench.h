$NetBSD$

--- filebench.h.orig	2011-09-06 17:17:45.000000000 +0000
+++ filebench.h
@@ -160,10 +160,12 @@ void filebench_plugin_funcvecinit(void);
 #define	FILEBENCH_RANDMAX FILEBENCH_RANDMAX32
 #endif
 
-#ifdef HAVE_PROC_PID_STAT
+#if defined(HAVE_GETTID)
+#if defined(HAVE_ASM_UNISTD_H)
 #include <asm/unistd.h>
 #define gettid() syscall(__NR_gettid)
 #endif
+#endif
 
 #ifndef HAVE_SIGIGNORE
 /* No sigignore on FreeBSD */
