$NetBSD$

Fix typecasting

--- net/crypt-rijndael.cpp.orig	2008-12-10 20:50:35.000000000 +0000
+++ net/crypt-rijndael.cpp	2008-12-10 20:53:37.000000000 +0000
@@ -103,11 +103,11 @@
     // The vic framework gives us an md5 hash which is 16 bytes long.
     //
     int keylen = 16;
-    rc = makeKey(&keyInstEncrypt_, DIR_ENCRYPT, keylen * 8, (BYTE *) key);
+    rc = makeKey(&keyInstEncrypt_, DIR_ENCRYPT, keylen * 8, (char *) key);
     if (rc < 0)
 	debug_msg("makeKey failed: %d\n", rc);
 
-    rc = makeKey(&keyInstDecrypt_, DIR_DECRYPT, keylen * 8, (BYTE *) key);
+    rc = makeKey(&keyInstDecrypt_, DIR_DECRYPT, keylen * 8, (char *) key);
     if (rc < 0)
 	debug_msg("makeKey failed: %d\n", rc);
 
