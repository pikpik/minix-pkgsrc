$NetBSD$

--- mozilla/ipc/chromium/src/chrome/common/ipc_channel_posix.cc.orig	2012-08-27 04:49:15.000000000 +0000
+++ mozilla/ipc/chromium/src/chrome/common/ipc_channel_posix.cc
@@ -7,6 +7,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <stddef.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
