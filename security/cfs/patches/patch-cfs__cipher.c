$NetBSD$

--- cfs_cipher.c.orig	2012-10-26 03:56:31.000000000 +0000
+++ cfs_cipher.c
@@ -70,10 +70,7 @@ cipher(k,s,d)
 	}
 }
 
-mask_cipher(k,s,d)
-     cfskey *k;
-     unsigned char *s;
-     int d;
+void mask_cipher(cfskey *k, unsigned char *s, int d)
 {
 	d=d&1;
 	switch (k->cipher) {
