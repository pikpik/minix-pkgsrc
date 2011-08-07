$NetBSD$

--- src/tiffread.c.orig	2011-01-25 14:10:44.000000000 +0000
+++ src/tiffread.c	2011-04-17 13:37:39.000000000 +0000
@@ -28,6 +28,8 @@
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define uint16 uint16_t
+#define uint32 uint32_t
 
 #include <tiffio.h>
 
