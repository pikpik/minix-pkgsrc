$NetBSD$

Fix #include

--- special.c.orig	2011-03-23 09:08:08.000000000 +0000
+++ special.c
@@ -26,7 +26,7 @@
 
 #ifndef MIKTEX
 #ifndef WIN32
-#include <wait.h>
+#include <sys/wait.h>
 #else /* WIN32 */
 #include <fcntl.h>
 #include <io.h>
