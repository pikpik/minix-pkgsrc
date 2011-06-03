--- readconf.c.orig	Fri Jun  3 12:11:04 2011
+++ readconf.c	Fri Jun  3 12:11:25 2011
@@ -19,8 +19,11 @@
 #include <sys/socket.h>
 
 #include <netinet/in.h>
+
+#ifndef __minix
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
+#endif
 
 #include <ctype.h>
 #include <errno.h>
