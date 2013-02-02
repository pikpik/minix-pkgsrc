$NetBSD$

* alloca.h is required for alloca(3C) on Solaris.
* Not all systems provide MSG_NOSIGNAL.

--- extras/immodules/common/scim-bridge-output.h.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/common/scim-bridge-output.h	2012-09-26 07:56:02.073082321 +0000
@@ -28,6 +28,14 @@
 #include "scim-bridge.h"
 #include "scim-bridge-debug.h"
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 #ifdef __cplusplus
 extern "C"
 {
