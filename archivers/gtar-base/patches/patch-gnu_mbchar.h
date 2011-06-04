--- gnu/mbchar.h.orig	Tue May 31 17:27:46 2011
+++ gnu/mbchar.h	Tue May 31 17:27:59 2011
--- gnu/mbchar.h.orig	Sat Mar 12 09:14:30 2011
+++ gnu/mbchar.h
@@ -156,7 +156,10 @@
 #include <stdio.h>
 #include <time.h>
 #include <wchar.h>
+
+#ifndef _MINIX
 #include <wctype.h>
+#endif
 
 #define MBCHAR_BUF_SIZE 24
 
