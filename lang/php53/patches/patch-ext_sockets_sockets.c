$NetBSD$

* Update of r311369 of PHP's repository, fix for CVE-2011-1938.

--- ext/sockets/sockets.c.orig	2011-01-01 02:19:59.000000000 +0000
+++ ext/sockets/sockets.c
@@ -1333,6 +1333,11 @@ PHP_FUNCTION(socket_connect)
 			break;
 
 		case AF_UNIX:
+			if (addr_len >= sizeof(s_un.sun_path)) {
+				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Path too long", php_sock->type);
+				RETURN_FALSE;
+			}
+
 			memset(&s_un, 0, sizeof(struct sockaddr_un));
 
 			s_un.sun_family = AF_UNIX;
