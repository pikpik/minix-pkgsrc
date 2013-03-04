$NetBSD$

--- lib/lbxutil/lbx_zlib/lbx_zlib_io.c.orig	Sun Aug  1 11:51:03 2010
+++ lib/lbxutil/lbx_zlib/lbx_zlib_io.c
@@ -39,16 +39,11 @@
 
 #include <stddef.h>
 
-#ifdef _MINIX
-/* Avoid writev compilation problem under gcc. */
-#define writev my_writev
-#endif
-
 /*
  * The following is taken from the xtrans code, almost as is,
  * it would be nice to share it...
  */
-#if defined(WIN32) || defined(__sxg__) || (defined(SCO) && !defined(SVR4) && !defined(SCO325)) || defined(MINIX3)
+#if defined(WIN32) || defined(__sxg__) || (defined(SCO) && !defined(SVR4) && !defined(SCO325))
 #  define ESET(val) errno = val
 static int
 writev(int fildes, const struct iovec *iov, int iovcnt)
