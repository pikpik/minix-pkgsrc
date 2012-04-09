$NetBSD$

--- lib/xtrans/Xtranssock_mnx3.c.orig	Sun Aug  1 11:51:53 2010
+++ lib/xtrans/Xtranssock_mnx3.c
@@ -2661,17 +2661,20 @@ static char* unix_nolisten[] = { "local" , NULL };
 
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
 
-static int _tcp_getsockname(int socket, struct sockaddr *_RESTRICT address,
-	socklen_t *_RESTRICT address_len, nwio_tcpconf_t *tcpconfp);
-
 #if 0
-static int getsockname(int socket, struct sockaddr *_RESTRICT address,
-	socklen_t *_RESTRICT address_len)
+static int _tcp_getsockname(int socket, struct sockaddr *_restrict address,
+	socklen_t *_restrict address_len, nwio_tcpconf_t *tcpconfp);
+
+static int getsockname(int socket, struct sockaddr *_restrict address,
+	socklen_t *_restrict address_len)
 {
 	int r;
 	nwio_tcpconf_t tcpconf;
@@ -2689,10 +2692,9 @@ static int getsockname(int socket, struct sockaddr *_R
 	}
 	assert(0);
 }
-#endif
 
-static int _tcp_getsockname(int socket, struct sockaddr *_RESTRICT address,
-	socklen_t *_RESTRICT address_len, nwio_tcpconf_t *tcpconfp)
+static int _tcp_getsockname(int socket, struct sockaddr *_restrict address,
+	socklen_t *_restrict address_len, nwio_tcpconf_t *tcpconfp)
 {
 	socklen_t len;
 	struct sockaddr_in sin;
@@ -2710,3 +2712,4 @@ static int _tcp_getsockname(int socket, struct sockadd
 
 	return 0;
 }
+#endif
