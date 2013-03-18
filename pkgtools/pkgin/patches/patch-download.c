--- download.c.orig	Sun Jul 15 17:36:34 2012
+++ download.c	Mon Mar 18 02:45:36 2013
@@ -82,7 +82,7 @@
 	else
 		p = (char *)str_url; /* should not happen */
 
-#ifndef _MINIX /* XXX: SSIZE_MAX fails under MINIX */
+#ifndef __minix /* XXX: SSIZE_MAX fails under MINIX */
 	/* st.size is an off_t, it will be > SSIZE_MAX on 32 bits systems */
 	if (sizeof(st.size) == sizeof(SSIZE_MAX) && st.size > SSIZE_MAX - 1)
 		err(EXIT_FAILURE, "file is too large");
