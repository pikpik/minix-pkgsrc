$NetBSD$

--- lib/libdvbapi/dvbvideo.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libdvbapi/dvbvideo.c
@@ -25,8 +25,13 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __NetBSD__
+#include <sys/types.h>
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/types.h>
 #include <linux/dvb/video.h>
+#endif
 #include <errno.h>
 #include "dvbvideo.h"
 
