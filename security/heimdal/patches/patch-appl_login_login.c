$NetBSD$

--- appl/login/login.c.orig	Tue Jan 10 21:53:51 2012
+++ appl/login/login.c
@@ -82,7 +82,9 @@ start_logout_process(void)
     pid = fork();
     if(pid == 0) {
 	/* avoid getting signals sent to the shell */
+#ifndef __minix
 	setpgid(0, getpid());
+#endif
 	return 0;
     }
     if(pid == -1)
