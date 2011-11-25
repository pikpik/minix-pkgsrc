$NetBSD$

--- src/FbTk/TextBox.cc.orig	2011-11-25 17:42:54.000000000 +0000
+++ src/FbTk/TextBox.cc
@@ -32,6 +32,7 @@
 #else
   #include <ctype.h>
 #endif
+#include <cstdlib>
 #include <X11/keysym.h>
 #include <X11/Xutil.h>
 
