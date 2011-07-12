$NetBSD$

--- lib/stdio-impl.h.orig	Tue Mar  1 16:39:29 2011
+++ lib/stdio-impl.h
@@ -55,7 +55,7 @@
 #  define fp_ fp
 # endif
 
-# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ /* NetBSD >= 1.5ZA, OpenBSD */
+# if (defined __NetBSD__ && __NetBSD_Version__ >= 105270000) || defined __OpenBSD__ || defined __minix /* NetBSD >= 1.5ZA, OpenBSD */
   /* See <http://cvsweb.netbsd.org/bsdweb.cgi/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup>
      and <http://www.openbsd.org/cgi-bin/cvsweb/src/lib/libc/stdio/fileext.h?rev=HEAD&content-type=text/x-cvsweb-markup> */
   struct __sfileext
