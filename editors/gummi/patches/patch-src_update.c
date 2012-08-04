$NetBSD$

--- src/update.c.orig	2012-06-24 16:52:03.000000000 +0000
+++ src/update.c
@@ -44,6 +44,10 @@
 #include "environment.h"
 #include "utils.h"
 
+#ifdef __NetBSD__
+#include <netinet/in.h>
+#endif
+
 #ifdef WIN32
 /* TODO: use Winsock for WIN32 */
 #else
