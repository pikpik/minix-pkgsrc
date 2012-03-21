$NetBSD$

--- src/input/input_dvb.c.orig	2012-02-04 00:41:43.000000000 +0000
+++ src/input/input_dvb.c
@@ -109,8 +109,12 @@
 /* XDG */
 #include <basedir.h>
 
+#ifdef HAVE_DEV_DTV_DTVIO_H
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/dmx.h>
 #include <linux/dvb/frontend.h>
+#endif
 
 #define LOG_MODULE "input_dvb"
 #define LOG_VERBOSE
