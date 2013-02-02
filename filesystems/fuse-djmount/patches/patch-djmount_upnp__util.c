$NetBSD$

* upnp header files will not include string.h anymore.

--- djmount/upnp_util.c.orig	2006-08-27 20:12:20.000000000 +0000
+++ djmount/upnp_util.c
@@ -28,6 +28,10 @@
 #	include <config.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#	include <string.h>
+#endif
+
 #include "upnp_util.h"
 #include "log.h"
 #include "xml_util.h"
