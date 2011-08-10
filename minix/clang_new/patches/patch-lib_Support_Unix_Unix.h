$NetBSD$

--- lib/Support/Unix/Unix.h.orig	Thu Aug 11 01:06:26 2011
+++ lib/Support/Unix/Unix.h
@@ -84,4 +84,9 @@ static inline bool MakeErrMsg(
   return true;
 }
 
+#ifdef __minix
+#define mmap minix_mmap
+#define munmap minix_munmap
+#endif
+
 #endif
