$NetBSD$

--- unix/tclUnixChan.c.orig	Tue Nov 28 16:29:48 2006
+++ unix/tclUnixChan.c
@@ -17,6 +17,11 @@
 #include "tclPort.h"	/* Portability features for Tcl. */
 #include "tclIO.h"	/* To get Channel type declaration. */
 
+#ifdef _MINIX
+   #define TIOCMGET 0x5415
+   #define TIOCMSET 0x5418
+#endif
+
 /*
  * sys/ioctl.h has already been included by tclPort.h.	Including termios.h
  * or termio.h causes a bunch of warning messages because some duplicate
