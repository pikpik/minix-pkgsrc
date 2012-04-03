$NetBSD$

--- lib/file.c.orig	2008-05-06 03:38:11.000000000 +0200
+++ lib/file.c	2011-12-29 13:41:30.765248351 +0100
@@ -17,6 +17,10 @@
 #include <sys/param.h>    /* for MIN(a,b) */
 #include <zlib.h>
 
+#ifndef MIN
+#define MIN(a, b) ((a) < (b) ? (a) : (b))
+#endif
+
 #define VERBOSE 3
 
 #define ror8(x,n)   (((x) >> ((int)(n))) | ((x) << (8 - (int)(n))))
