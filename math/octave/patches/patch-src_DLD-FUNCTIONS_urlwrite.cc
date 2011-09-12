$NetBSD$

* not to include deprecated CURL header file. 

--- src/DLD-FUNCTIONS/urlwrite.cc.orig	2009-05-25 06:05:00.000000000 +0000
+++ src/DLD-FUNCTIONS/urlwrite.cc
@@ -46,7 +46,6 @@ along with Octave; see the file COPYING.
 #if defined (HAVE_CURL)
 
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 
 // Write callback function for curl.
