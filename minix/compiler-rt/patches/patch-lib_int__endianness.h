$NetBSD$

--- lib/int_endianness.h.orig	Tue Nov 29 00:14:28 2011
+++ lib/int_endianness.h
@@ -31,7 +31,7 @@
 
 /* .. */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__minix)
 #include <sys/endian.h>
 
 #if _BYTE_ORDER == _BIG_ENDIAN
