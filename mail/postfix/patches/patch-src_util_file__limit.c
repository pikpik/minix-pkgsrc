$NetBSD$

--- src/util/file_limit.c.orig	Wed Oct 22 18:48:36 2003
+++ src/util/file_limit.c
@@ -79,6 +79,9 @@ off_t   get_file_limit(void)
 
 void    set_file_limit(off_t limit)
 {
+#ifdef MINIX3
+	return;
+#else
 #ifdef USE_ULIMIT
     if (ulimit(UL_SETFSIZE, limit / ULIMIT_BLOCK_SIZE) < 0)
 	msg_fatal("ulimit: %m");
@@ -93,4 +96,5 @@ void    set_file_limit(off_t limit)
 	msg_fatal("signal(SIGXFSZ,SIG_IGN): %m");
 #endif
 #endif						/* USE_ULIMIT */
+#endif
 }
