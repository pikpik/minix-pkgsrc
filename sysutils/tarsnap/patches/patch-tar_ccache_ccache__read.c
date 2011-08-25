$NetBSD$

--- tar/ccache/ccache_read.c.orig	Mon Feb  7 23:59:46 2011
+++ tar/ccache/ccache_read.c
@@ -17,6 +17,58 @@
 
 #include "ccache.h"
 
+#ifdef __minix
+
+/* minix3 only supports memory-allocating mmap; we can simulate
+ * an mmap that can read a file with MAP_PRIVATE by reading the
+ * file contents ourselves.
+ */
+static void *mmap(void *rqaddr, size_t len, int prot, int flags,
+	int fd, off_t position)
+{
+	void *addr;
+	ssize_t r;
+	off_t curoff;
+	errno = 0;
+	curoff = lseek(fd, 0, SEEK_CUR);
+	if(curoff < 0) {
+		fprintf(stderr, "minix mmap: initial lseek failed\n");
+		return MAP_FAILED;
+	}
+	if(lseek(fd, position, SEEK_SET) < 0) {
+		fprintf(stderr, "minix mmap: real lseek failed\n");
+		return MAP_FAILED;
+	}
+	if(!(flags & MAP_PRIVATE)) {
+		fprintf(stderr, "minix mmap: can only simulate MAP_PRIVATE\n");
+		return MAP_FAILED;
+	}
+	addr = minix_mmap(rqaddr, len, PROT_READ | PROT_WRITE,
+		MAP_ANON | MAP_PREALLOC, -1, 0);
+	if(addr == MAP_FAILED) {
+		fprintf(stderr, "minix mmap: mmap of 0x%lx bytes failed\n",
+			len);
+		return addr;
+	}
+	if((r=read(fd, addr, len)) != len) {
+		minix_munmap(addr, len);
+		fprintf(stderr, "minix mmap: short read of 0x%lx / 0x%lx bytes\n",
+			r, len);
+		/* return MAP_FAILED; */
+	}
+	if(lseek(fd, curoff, SEEK_SET) < 0) {
+		fprintf(stderr, "minix mmap: restore lseek failed\n");
+		abort();
+	}
+	return addr;
+}
+
+int munmap(void *addr, size_t len)
+{
+	return minix_munmap(addr, len);
+}
+#endif
+
 /* Cookie structure passed to read_rec and callback_read_data. */
 struct ccache_read_internal {
 	size_t N;	/* Number of records. */
