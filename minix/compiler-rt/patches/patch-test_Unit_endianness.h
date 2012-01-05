$NetBSD$

--- test/Unit/endianness.h.orig	Tue Nov 29 00:14:28 2011
+++ test/Unit/endianness.h
@@ -36,7 +36,7 @@
 
 /* .. */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonflyBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonflyBSD__) || defined(__minix)
 #include <sys/endian.h>
 
 #if _BYTE_ORDER == _BIG_ENDIAN
