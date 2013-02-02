$NetBSD$

Use correct size for malloc.

Not yet reported upstream.

--- src/pkcs11/pkcs11-global.c.orig	2011-07-05 11:28:53.000000000 +0000
+++ src/pkcs11/pkcs11-global.c
@@ -42,7 +42,7 @@ extern CK_FUNCTION_LIST pkcs11_function_
 #include <pthread.h>
 CK_RV mutex_create(void **mutex)
 {
-	pthread_mutex_t *m = malloc(sizeof(*mutex));
+	pthread_mutex_t *m = malloc(sizeof(*m));
 	if (m == NULL)
 		return CKR_GENERAL_ERROR;;
 	pthread_mutex_init(m, NULL);
