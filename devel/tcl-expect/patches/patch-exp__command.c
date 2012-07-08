$NetBSD$

--- exp_command.c.orig	Fri Aug 20 17:18:01 2004
+++ exp_command.c
@@ -523,11 +523,13 @@ expSetpgrp()
     syscall(SYS_setpgrp);
 #endif
 
+#ifndef _MINIX
 #ifdef SETPGRP_VOID
     (void) setpgrp();
 #else
     (void) setpgrp(0,0);
 #endif
+#endif /* _MINIX */
 }
 
 
@@ -790,7 +792,7 @@ when trapping, see below in child half of fork */
 	 * process "-open $channel"
 	 */
 	int mode;
-	int rfd, wfd;
+	long rfd, wfd;
 	ClientData rfdc, wfdc;
 	
 	if (echo) {
