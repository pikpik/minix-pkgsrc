$NetBSD$

--- lib/crypto/crypto_scrypt-nosse.c.orig	Mon Feb  7 23:59:45 2011
+++ lib/crypto/crypto_scrypt-nosse.c
@@ -221,6 +221,15 @@ smix(uint8_t * B, size_t r, uint64_t N, uint32_t * V, 
 		le32enc(&B[4 * k], X[k]);
 }
 
+#ifdef __minix
+/* minix3 has a mmap() that can only allocate memory, and is therefore
+ * hidden behind its own name. As this file uses mmap() only for that
+ * purpose, we can let it use the minix mmap.
+ */
+#define mmap minix_mmap
+#define munmap minix_munmap
+#endif
+
 /**
  * crypto_scrypt(passwd, passwdlen, salt, saltlen, N, r, p, buf, buflen):
  * Compute scrypt(passwd[0 .. passwdlen - 1], salt[0 .. saltlen - 1], N, r,
