$NetBSD$

--- util/szap/tzap.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/szap/tzap.c
@@ -32,8 +32,16 @@
 #include <errno.h>
 #include <signal.h>
 
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
+
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
 #include <linux/dvb/dmx.h>
+#endif
 
 #include "util.h"
 
