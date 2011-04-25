$NetBSD$

--- mysys/stacktrace.c.orig	2011-03-31 13:36:16.000000000 +0000
+++ mysys/stacktrace.c
@@ -421,7 +421,7 @@ void my_write_core(int sig)
   __gcov_flush();
 #endif
   pthread_kill(pthread_self(), sig);
-#if defined(P_MYID) && !defined(SCO)
+#if HAVE_SIGSEND && defined(P_MYID) && !defined(SCO)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID,P_MYID,sig);
 #endif
