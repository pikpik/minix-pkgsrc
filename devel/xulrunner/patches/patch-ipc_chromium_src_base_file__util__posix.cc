$NetBSD$

--- ipc/chromium/src/base/file_util_posix.cc.orig	2011-12-20 23:28:19.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -31,7 +31,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef __linux__
 #define stat64 stat
 #endif
 
