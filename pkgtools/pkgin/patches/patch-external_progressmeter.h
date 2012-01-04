$NetBSD$

--- external/progressmeter.h.orig	Thu Aug 11 00:27:58 2011
+++ external/progressmeter.h
@@ -32,5 +32,9 @@
 #include <termios.h>
 #endif
 
+#ifdef __minix
+#undef HAVE_TCGETPGRP
+#endif
+
 void	start_progress_meter(char *, off_t, off_t *);
 void	stop_progress_meter(void);
