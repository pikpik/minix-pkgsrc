$NetBSD$

--- src/gtk/gtk-single-url.cc.orig	2011-11-25 18:42:19.000000000 +0000
+++ src/gtk/gtk-single-url.cc
@@ -13,6 +13,7 @@
 
 #include <config.h>
 
+#include <cstring>
 #include <time.h>
 #include <errno.h>
 
