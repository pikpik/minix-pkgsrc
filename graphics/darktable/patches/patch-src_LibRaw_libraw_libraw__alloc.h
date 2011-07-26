$NetBSD$

Work around redefined symbol.

--- src/LibRaw/libraw/libraw_alloc.h.orig	2011-07-02 03:15:32.000000000 +0000
+++ src/LibRaw/libraw/libraw_alloc.h
@@ -27,6 +27,7 @@ it under the terms of the one of three l
 
 #ifdef __cplusplus
 
+#undef MSIZE
 #define MSIZE 32
 
 class DllDef libraw_memmgr
