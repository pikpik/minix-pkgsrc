$NetBSD$

--- extras/immodules/common/scim-bridge-messenger.h.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/common/scim-bridge-messenger.h
@@ -33,6 +33,8 @@
  */
 typedef struct _ScimBridgeMessenger ScimBridgeMessenger;
 
+struct timeval;
+
 #ifdef __cplusplus
 extern "C"
 {
