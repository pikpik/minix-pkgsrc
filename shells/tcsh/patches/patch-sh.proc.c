--- sh.proc.c.orig	Wed Jan 25 15:34:41 2012
+++ sh.proc.c	Wed Mar 13 13:25:48 2013
@@ -1833,12 +1833,12 @@
 	    (void) signal(SIGHUP, SIG_IGN);
 	if (t->t_dflg & F_NICE) {
 	    int nval = SIGN_EXTEND_CHAR(t->t_nice);
-#ifdef HAVE_SETPRIORITY
+#if defined(HAVE_SETPRIORITY) && defined(PRIO_PROCESS)
 	    if (setpriority(PRIO_PROCESS, 0, nval) == -1 && errno)
 		stderror(ERR_SYSTEM, "setpriority", strerror(errno));
-#else /* !HAVE_SETPRIORITY */
+#else /* ! (HAVE_SETPRIORITY && PRIO_PROCESS) */
 	    (void) nice(nval);
-#endif /* !HAVE_SETPRIORITY */
+#endif /* HAVE_SETPRIORITY && PRIO_PROCESS */
 	}
 #ifdef F_VER
         if (t->t_dflg & F_VER) {
