$NetBSD$

--- src/pulsecore/macro.h.orig	2009-09-18 22:21:44.000000000 +0200
+++ src/pulsecore/macro.h	2011-09-08 12:44:25.798236549 +0200
@@ -37,6 +37,10 @@
 #error "Please include config.h before including this file!"
 #endif
 
+#ifdef __sun
+#define typeof	__typeof__
+#endif
+
 #ifndef PA_LIKELY
 #ifdef __GNUC__
 #define PA_LIKELY(x) (__builtin_expect(!!(x),1))
