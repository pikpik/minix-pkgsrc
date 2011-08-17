$NetBSD$

--- src/support/ab.c.orig	Wed Jul 12 08:16:05 2006
+++ src/support/ab.c
@@ -411,7 +411,11 @@ static void nonblock(int fd)
 #ifdef BEOS
     setsockopt(fd, SOL_SOCKET, SO_NONBLOCK, &i, sizeof(i));
 #else
+#ifdef FIONBIO
     ioctl(fd, FIONBIO, &i);
+#else
+    fcntl(fd, F_SETFL, O_NONBLOCK);
+#endif
 #endif
 }
 
