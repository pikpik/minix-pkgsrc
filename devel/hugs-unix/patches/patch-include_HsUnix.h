$NetBSD$

--- include/HsUnix.h.orig	2013-03-24 15:10:05.000000000 +0000
+++ include/HsUnix.h
@@ -82,13 +82,7 @@
 
 extern char **environ;
 
-#ifndef INLINE
-# if defined(__GNUC__)
-#  define INLINE extern inline
-# else
-#  define INLINE inline
-# endif
-#endif
+#define INLINE static inline
 
 INLINE int __hsunix_wifexited   (int stat) { return WIFEXITED(stat); }
 INLINE int __hsunix_wexitstatus (int stat) { return WEXITSTATUS(stat); }
