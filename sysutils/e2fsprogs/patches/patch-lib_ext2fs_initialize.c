$NetBSD$

--- lib/ext2fs/initialize.c.orig	Tue May 18 03:04:39 2010
+++ lib/ext2fs/initialize.c
@@ -39,7 +39,11 @@
 #if defined(LITES) 	   &&	defined(EXT2_OS_LITES)
 #define CREATOR_OS EXT2_OS_LITES
 #else
+#if defined(__minix)   &&      defined(EXT2_OS_MINIX)
+#define CREATOR_OS EXT2_OS_MINIX
+#else
 #define CREATOR_OS EXT2_OS_LINUX /* by default */
+#endif /* defined(__minix) && defined(EXT2_OS_MINIX) */
 #endif /* defined(LITES) && defined(EXT2_OS_LITES) */
 #endif /* defined(__FreeBSD__) && defined(EXT2_OS_FREEBSD) */
 #endif /* defined(__GNU__)     && defined(EXT2_OS_HURD) */
