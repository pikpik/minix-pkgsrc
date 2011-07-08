$NetBSD$

--- unix/unix.c.orig	Fri Jan 23 23:31:26 2009
+++ unix/unix.c
@@ -46,6 +46,16 @@
 #  endif
 #endif
 
+#ifdef __minix
+#  include <unistd.h>
+#  ifndef lchown
+#    define lchown chown
+#  endif
+#  ifndef lchmod
+#    define lchmod chmod
+#  endif
+#endif
+
 #ifdef _POSIX_VERSION
 #  ifndef DIRENT
 #    define DIRENT
