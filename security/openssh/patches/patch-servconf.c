--- servconf.c.orig	Fri Jun  3 12:18:54 2011
+++ servconf.c	Fri Jun  3 12:19:10 2011
@@ -16,8 +16,11 @@
 #include <sys/socket.h>
 
 #include <netinet/in.h>
+
+#ifndef __minix
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
+#endif
 
 #include <netdb.h>
 #include <pwd.h>
