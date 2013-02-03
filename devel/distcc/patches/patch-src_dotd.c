$NetBSD$

Use system vsnprintf() as intended (fixes build on OS X 10.6).

--- src/dotd.c.orig	2008-12-02 21:50:25.000000000 +0000
+++ src/dotd.c
@@ -18,6 +18,8 @@
  * USA.
  */
 
+#include <config.h>
+
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
