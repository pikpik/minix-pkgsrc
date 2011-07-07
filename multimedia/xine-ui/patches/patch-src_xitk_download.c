$NetBSD$

* not to include deprecated header file of curl.

--- src/xitk/download.c.orig	2009-12-19 00:34:22.000000000 +0000
+++ src/xitk/download.c
@@ -28,7 +28,6 @@
 
 #ifdef HAVE_CURL
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
