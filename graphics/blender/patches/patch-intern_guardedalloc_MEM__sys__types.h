$NetBSD$

--- intern/guardedalloc/MEM_sys_types.h.orig	2012-10-09 18:34:13.000000000 +0000
+++ intern/guardedalloc/MEM_sys_types.h
@@ -131,7 +131,7 @@ unsigned long __attribute__((__stdcall__
 #define ntohl(x) correctByteOrder(x)
 #endif
 #endif
-#elif defined (__FreeBSD__) || defined (__OpenBSD__) 
+#elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
 #include <sys/param.h>
 #elif defined (__APPLE__)
 #include <sys/types.h>
