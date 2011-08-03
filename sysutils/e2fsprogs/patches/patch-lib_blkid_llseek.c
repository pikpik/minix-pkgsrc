$NetBSD$

--- lib/blkid/llseek.c.orig	Thu Aug 13 01:39:57 2009
+++ lib/blkid/llseek.c
@@ -126,7 +126,14 @@ blkid_loff_t blkid_llseek(int fd, blkid_loff_t offset,
 blkid_loff_t blkid_llseek(int fd, blkid_loff_t offset, int origin)
 {
 #if defined(HAVE_LSEEK64) && defined(HAVE_LSEEK64_PROTOTYPE)
+#ifndef __minix
 	return lseek64 (fd, offset, origin);
+#else
+	u64_t newpos;
+	if(lseek64 (fd, offset, origin, &newpos) < 0)
+		return -1;
+	return newpos;
+#endif
 #else
 	if ((sizeof(off_t) < sizeof(blkid_loff_t)) &&
 	    (offset >= ((blkid_loff_t) 1 << ((sizeof(off_t)*8) - 1)))) {
