$NetBSD$

--- lib/Support/Unix/Unix.h.orig	Thu Jun 28 00:55:40 2012
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
