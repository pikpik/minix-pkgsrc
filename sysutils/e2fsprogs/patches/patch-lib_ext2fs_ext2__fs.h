$NetBSD$

--- lib/ext2fs/ext2_fs.h.orig	Tue May 18 01:25:49 2010
+++ lib/ext2fs/ext2_fs.h
@@ -592,6 +592,7 @@ struct ext2_super_block {
 #define EXT2_OBSO_OS_MASIX	2
 #define EXT2_OS_FREEBSD		3
 #define EXT2_OS_LITES		4
+#define EXT2_OS_MINIX          5
 
 /*
  * Revision levels
