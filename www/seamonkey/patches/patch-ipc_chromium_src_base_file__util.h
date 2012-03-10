$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.1 2011/07/11 20:46:36 tnn Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2012-02-16 14:09:02.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -16,8 +16,8 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
-#include <fts.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
