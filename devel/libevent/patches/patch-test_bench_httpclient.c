--- test/bench_httpclient.c.orig	Thu Jul 26 14:20:26 2012
+++ test/bench_httpclient.c	Sun Mar 17 01:30:50 2013
@@ -113,14 +113,18 @@
 static void
 frob_socket(evutil_socket_t sock)
 {
+#ifdef SO_LINGER
 	struct linger l;
+#endif
 	int one = 1;
 	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (void*)&one, sizeof(one))<0)
 		perror("setsockopt(SO_REUSEADDR)");
+#ifdef SO_LINGER
 	l.l_onoff = 1;
 	l.l_linger = 0;
 	if (setsockopt(sock, SOL_SOCKET, SO_LINGER, (void*)&l, sizeof(l))<0)
 		perror("setsockopt(SO_LINGER)");
+#endif
 }
 
 static int
