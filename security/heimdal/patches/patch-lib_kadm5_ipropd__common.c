$NetBSD$

--- lib/kadm5/ipropd_common.c.orig	Tue Jan 10 21:53:51 2012
+++ lib/kadm5/ipropd_common.c
@@ -55,7 +55,9 @@ setup_signal(void)
 
 	sigaction(SIGINT, &sa, NULL);
 	sigaction(SIGTERM, &sa, NULL);
+#ifdef SIGXCPU
 	sigaction(SIGXCPU, &sa, NULL);
+#endif
 
 	sa.sa_handler = SIG_IGN;
 	sigaction(SIGPIPE, &sa, NULL);
