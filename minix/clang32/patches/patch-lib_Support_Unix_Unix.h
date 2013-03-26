$NetBSD$

--- lib/Support/Unix/Unix.h.orig	Mon Apr 23 19:00:27 2012
+++ lib/Support/Unix/Unix.h
@@ -78,4 +78,9 @@ static inline bool MakeErrMsg(
   return true;
 }
 
+#ifdef __minix
+#define mmap minix_mmap
+#define munmap minix_munmap
+#endif
+
 #endif
