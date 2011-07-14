$NetBSD$

--- signal.c.orig	Thu Jul 14 21:40:54 2011
+++ signal.c
@@ -26,6 +26,10 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 
+#ifdef __minix
+#include <minix/termios.h>
+#endif
+
 #include "ed.h"
 
 
