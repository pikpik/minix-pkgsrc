$NetBSD$

Use system vsnprintf() as intended (fixes build on OS X 10.6).

--- src/emaillog.c.orig	2008-12-02 21:50:24.000000000 +0000
+++ src/emaillog.c
@@ -18,6 +18,8 @@
  * USA.
  */
 
+#include <config.h>
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <errno.h>
