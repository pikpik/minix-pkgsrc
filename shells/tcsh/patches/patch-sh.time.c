--- sh.time.c.orig	Thu Dec  9 15:39:29 2010
+++ sh.time.c	Wed Mar 13 13:23:57 2013
@@ -158,12 +158,12 @@
 	nval = 4;
     else if (*v	== 0 &&	any("+-", cp[0]))
 	nval = getn(cp);
-#ifdef HAVE_SETPRIORITY
+#if defined(HAVE_SETPRIORITY) && defined(PRIO_PROCESS)
     if (setpriority(PRIO_PROCESS, 0, nval) == -1 && errno)
 	stderror(ERR_SYSTEM, "setpriority", strerror(errno));
-#else /* !HAVE_SETPRIORITY */
+#else /* ! (HAVE_SETPRIORITY && PRIO_PROCESS) */
     (void) nice(nval);
-#endif /* HAVE_SETPRIORITY */
+#endif /* HAVE_SETPRIORITY && PRIO_PROCESS */
 }
 
 #ifdef BSDTIMES
