$NetBSD$

--- include/IL/il.h.orig	2012-07-06 12:31:13.000000000 +0000
+++ include/IL/il.h
@@ -63,7 +63,7 @@ extern "C" {
 	#endif
 #endif
 
-#ifdef RESTRICT_KEYWORD
+#if defined(RESTRICT_KEYWORD) && !defined(__cplusplus)
 #define RESTRICT restrict
 #define CONST_RESTRICT const restrict
 #else
