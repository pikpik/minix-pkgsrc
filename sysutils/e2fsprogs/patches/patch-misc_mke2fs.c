$NetBSD$

--- misc/mke2fs.c.orig	Tue May 18 03:04:40 2010
+++ misc/mke2fs.c
@@ -678,6 +678,8 @@ static int set_os(struct ext2_super_block *sb, char *o
 		sb->s_creator_os = EXT2_OS_FREEBSD;
 	else if (strcasecmp(os, "lites") == 0)
 		sb->s_creator_os = EXT2_OS_LITES;
+        else if (strcasecmp(os, "minix") == 0)
+               sb->s_creator_os = EXT2_OS_MINIX;
 	else
 		return 0;
 	return 1;
