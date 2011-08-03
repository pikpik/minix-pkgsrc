$NetBSD$

--- misc/e2image.c.orig	Thu May 13 22:59:49 2010
+++ misc/e2image.c
@@ -316,9 +316,12 @@ static void write_block(int fd, char *buf, int sparse_
 
 	if (sparse_offset) {
 #ifdef HAVE_LSEEK64
-		if (lseek64(fd, sparse_offset, SEEK_CUR) < 0)
+		if (lseek64(fd, sparse_offset, SEEK_CUR
+#ifdef __minix
+	, NULL
+#endif
+		) < 0)
 			perror("lseek");
-#else
 		if (lseek(fd, sparse_offset, SEEK_CUR) < 0)
 			perror("lseek");
 #endif
