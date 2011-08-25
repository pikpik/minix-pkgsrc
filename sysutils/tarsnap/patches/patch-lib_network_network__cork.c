$NetBSD$

--- lib/network/network_cork.c.orig	Mon Feb  7 23:59:45 2011
+++ lib/network/network_cork.c
@@ -50,7 +50,9 @@
 int
 network_cork(int fd)
 {
-
+#ifdef __minix
+	return 0;
+#else
 	/* Clear TCP_NODELAY. */
 	setopt(fd, TCP_NODELAY, 0, err0);
 
@@ -71,6 +73,7 @@ network_cork(int fd)
 err0:
 	/* Failure! */
 	return (-1);
+#endif
 }
 
 /**
@@ -81,7 +84,9 @@ err0:
 int
 network_uncork(int fd)
 {
-
+#ifdef __minix
+	return 0;
+#else
 	/* Clear TCP_CORK or TCP_NOPUSH as appropriate. */
 #ifdef TCP_CORK
 	setopt(fd, TCP_CORK, 0, err0);
@@ -106,5 +111,6 @@ network_uncork(int fd)
 err0:
 	/* Failure! */
 	return (-1);
+#endif
 }
 
