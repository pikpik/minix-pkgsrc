$NetBSD$

--- src/npp_gate.cpp.orig	2011-12-29 14:05:17.000000000 +0000
+++ src/npp_gate.cpp
@@ -44,7 +44,7 @@
 #include "plugin_types.h"
 #include "plugin_setup.h"
 
-char *NPP_GetMIMEDescription(void)
+const char *NPP_GetMIMEDescription(void)
 {
     return GetMIMEDescription();
 }
