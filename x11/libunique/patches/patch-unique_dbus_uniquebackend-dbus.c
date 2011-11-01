$NetBSD$

--- unique/dbus/uniquebackend-dbus.c.orig	2009-11-01 20:15:26.000000000 +0100
+++ unique/dbus/uniquebackend-dbus.c	2011-10-20 14:18:38.936534307 +0200
@@ -84,7 +84,7 @@ unique_backend_dbus_register_proxy (Uniq
 static gboolean
 unique_backend_dbus_request_name (UniqueBackend *backend)
 {
-  UniqueBackendDBus *backend_dbus;
+  UniqueBackendDBus __attribute__((__unused__)) *backend_dbus;
   const gchar *name;
   DBusGConnection *connection;
   DBusGProxy *proxy;
@@ -186,7 +186,7 @@ unique_backend_dbus_send_message (Unique
   GValueArray *data;
   gchar *cmd;
   gchar *resp;
-  gboolean res;
+  gboolean __attribute__((__unused__)) res;
   GError *error;
   UniqueResponse response;
 
