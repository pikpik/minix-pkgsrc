$NetBSD$

--- lib/xtrans/Xtranssock_mnx3.c.orig	Thu Jul 14 12:00:30 2011
+++ lib/xtrans/Xtranssock_mnx3.c
@@ -2661,7 +2661,10 @@ static char* unix_nolisten[] = { "local" , NULL };
 
 /* Starting point of a socket library */
 #include <net/netlib.h>
-#include <net/ioctl.h>
+
+#include <sys/ioc_net.h> /* new location of Minix network ioctl definitions */
+/* #include <net/ioctl.h>   old location of Minix network ioctl definitions */
+
 #include <net/gen/in.h>
 #include <net/gen/tcp.h>
 #include <net/gen/tcp_io.h>
