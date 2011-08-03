$NetBSD$

--- lib/ext2fs/llseek.c.orig	Tue May 18 03:04:39 2010
+++ lib/ext2fs/llseek.c
@@ -122,7 +122,14 @@ ext2_loff_t ext2fs_llseek (int fd, ext2_loff_t offset,
 ext2_loff_t ext2fs_llseek (int fd, ext2_loff_t offset, int origin)
 {
 #if defined(HAVE_LSEEK64) && defined(HAVE_LSEEK64_PROTOTYPE)
+#ifdef __minix
+	u64_t newpos;
+	if(lseek64 (fd, offset, origin, &newpos) < 0)
+		return -1;
+	return newpos;
+#else
 	return lseek64 (fd, offset, origin);
+#endif
 #else
 	if ((sizeof(off_t) < sizeof(ext2_loff_t)) &&
 	    (offset >= ((ext2_loff_t) 1 << ((sizeof(off_t)*8) -1)))) {
