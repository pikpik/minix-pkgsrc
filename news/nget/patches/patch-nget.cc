$NetBSD$

--- nget.cc.orig	2011-12-06 17:02:32.000000000 +0000
+++ nget.cc
@@ -37,6 +37,7 @@ extern "C" {
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
+#include <limits.h>
 #include <time.h>
 #include "_fileconf.h"
 
