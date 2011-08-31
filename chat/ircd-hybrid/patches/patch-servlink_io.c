$NetBSD$

--- servlink/io.c.orig	Wed Feb 28 04:17:47 2007
+++ servlink/io.c
@@ -291,7 +291,9 @@ send_error(const char *message, ...)
 {
   va_list args;
   static int sending_error = 0;
+#ifndef __minix
   struct linger linger_opt = { 1, 30 }; /* wait 30 seconds */
+#endif
   int len;
 
   if (sending_error)
@@ -320,10 +322,12 @@ send_error(const char *message, ...)
 
   send_data_blocking(CONTROL_W.fd, in_state.buf, len);
 
+#ifndef __minix
   /* XXX - is this portable?
    *       this obviously will fail on a non socket.. */
   setsockopt(CONTROL_W.fd, SOL_SOCKET, SO_LINGER, &linger_opt,
              sizeof(struct linger));
+#endif
 
   /* well, we've tried... */
   exit(1); /* now abort */
