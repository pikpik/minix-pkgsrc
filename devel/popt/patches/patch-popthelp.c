--- popthelp.c.orig	Fri Aug 28 00:06:33 2009
+++ popthelp.c	Sat Mar 23 17:21:08 2013
@@ -15,6 +15,10 @@
 #include <sys/ioctl.h>
 #endif
 
+#ifdef __minix
+#include <termios.h>
+#endif
+
 #define	POPT_WCHAR_HACK
 #ifdef 	POPT_WCHAR_HACK
 #include <wchar.h>			/* for mbsrtowcs */
