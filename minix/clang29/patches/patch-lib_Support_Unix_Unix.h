$NetBSD$

--- lib/Support/Unix/Unix.h.orig	Fri Feb 11 02:26:01 2011
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
