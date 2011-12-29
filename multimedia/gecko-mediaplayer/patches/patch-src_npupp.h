$NetBSD$

--- src/npupp.h.orig	2011-12-29 14:02:31.000000000 +0000
+++ src/npupp.h
@@ -700,7 +700,7 @@ extern "C" {
 
 /* plugin meta member functions */
 
-    NP_EXPORT(char *) NP_GetMIMEDescription(void);
+    NP_EXPORT(const char *) NP_GetMIMEDescription(void);
      NP_EXPORT(NPError) NP_Initialize(NPNetscapeFuncs *, NPPluginFuncs *);
      NP_EXPORT(NPError) NP_Shutdown(void);
      NP_EXPORT(NPError) NP_GetValue(void *future, NPPVariable aVariable, void *aValue);
