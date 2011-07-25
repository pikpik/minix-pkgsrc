$NetBSD$

--- util/scan/dump-vdr.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/scan/dump-vdr.c
@@ -1,6 +1,10 @@
 #include <stdio.h>
 #include "dump-vdr.h"
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
+#endif
 
 
 static const char *inv_name [] = {
