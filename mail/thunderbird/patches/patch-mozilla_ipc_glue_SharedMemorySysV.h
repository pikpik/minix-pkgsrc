$NetBSD$

--- mozilla/ipc/glue/SharedMemorySysV.h.orig	2012-08-25 00:31:11.000000000 +0000
+++ mozilla/ipc/glue/SharedMemorySysV.h
@@ -8,7 +8,7 @@
 #ifndef mozilla_ipc_SharedMemorySysV_h
 #define mozilla_ipc_SharedMemorySysV_h
 
-#if defined(OS_LINUX) && !defined(ANDROID)
+#if defined(OS_LINUX) && !defined(ANDROID) || defined(OS_BSD)
 
 // SysV shared memory isn't available on Windows, but we define the
 // following macro so that #ifdefs are clearer (compared to #ifdef
