$NetBSD$

SunOS already has offset_t defined.
--- extra_lib/include/ffmpeg/avio.h.orig	2007-05-30 15:54:08.000000000 +0000
+++ extra_lib/include/ffmpeg/avio.h
@@ -23,7 +23,9 @@
 
 /* output byte stream handling */
 
+#if !defined(__sun)
 typedef int64_t offset_t;
+#endif
 
 /* unbuffered I/O */
 
