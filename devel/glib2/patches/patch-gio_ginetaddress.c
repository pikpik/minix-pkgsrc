$NetBSD$

--- gio/ginetaddress.c.orig	Sun Jun  5 23:18:49 2011
+++ gio/ginetaddress.c
@@ -484,7 +484,11 @@ g_inet_address_new_loopback (GSocketFamily family)
       return g_inet_address_new_from_bytes (addr, family);
     }
   else
+#ifdef __minix
+    return NULL;
+#else
     return g_inet_address_new_from_bytes (in6addr_loopback.s6_addr, family);
+#endif
 }
 
 /**
@@ -511,7 +515,11 @@ g_inet_address_new_any (GSocketFamily family)
       return g_inet_address_new_from_bytes (addr, family);
     }
   else
+#ifdef __minix
+    return NULL;
+#else
     return g_inet_address_new_from_bytes (in6addr_any.s6_addr, family);
+#endif
 }
 
 
