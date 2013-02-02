$NetBSD$

Add header for struct timeval.

--- src/util.h.orig	2012-04-11 04:05:42.000000000 +0000
+++ src/util.h
@@ -2,6 +2,7 @@
 #define UTIL_H
 
 #include <string.h>
+#include <sys/time.h>
 
 #include "config.h"
 
