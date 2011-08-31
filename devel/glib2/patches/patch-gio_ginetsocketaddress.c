$NetBSD$

--- gio/ginetsocketaddress.c.orig	Wed Jan  5 21:44:06 2011
+++ gio/ginetsocketaddress.c
@@ -185,7 +185,9 @@ g_inet_socket_address_to_native (GSocketAddress  *addr
       sock->sin_family = AF_INET;
       sock->sin_port = g_htons (addr->priv->port);
       memcpy (&(sock->sin_addr.s_addr), g_inet_address_to_bytes (addr->priv->address), sizeof (sock->sin_addr));
+#ifndef __minix
       memset (sock->sin_zero, 0, sizeof (sock->sin_zero));
+#endif
       return TRUE;
     }
   else if (family == AF_INET6)
