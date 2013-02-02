--- unix/tclUnixChan.c.orig	Tue Nov  6 15:05:00 2012
+++ unix/tclUnixChan.c	Fri Feb  1 19:57:36 2013
@@ -24,6 +24,12 @@
 #endif /* B4800 */
 
 #ifdef USE_TERMIOS
+
+#   ifdef __minix
+#       define TIOCMGET 0x5415
+#       define TIOCMSET 0x5418
+#   endif
+
 #   include <termios.h>
 #   ifdef HAVE_SYS_IOCTL_H
 #	include <sys/ioctl.h>
