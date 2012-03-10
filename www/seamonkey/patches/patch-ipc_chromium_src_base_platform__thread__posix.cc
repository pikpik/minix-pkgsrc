$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.2 2011/08/01 08:17:17 tnn Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2012-02-16 14:09:02.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,9 +9,13 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#elif defined(OS_NETBSD)
+#include <lwp.h>
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <unistd.h>
+#elif defined(OS_DRAGONFLY)
+#include <unistd.h>
 #endif
 
 #if defined(OS_MACOSX)
@@ -33,6 +37,14 @@ PlatformThreadId PlatformThread::Current
   // into the kernel.
 #if defined(OS_MACOSX)
   return mach_thread_self();
+#elif defined(OS_NETBSD)
+  return _lwp_self();
+#elif defined(OS_DRAGONFLY)
+  return lwp_gettid();
+#elif defined(OS_FREEBSD)
+  lwpid_t lwpid;
+  thr_self( &lwpid );
+  return lwpid;
 #elif defined (__OpenBSD__)
   // TODO(BSD): find a better thread ID
   return (intptr_t)(pthread_self());
