$NetBSD$

--- tcl.cc.orig	2004-01-13 05:31:28.000000000 +0000
+++ tcl.cc
@@ -6,6 +6,7 @@
 #include <dmalloc.h>
 #endif
 
+#include <string.h>
 #include "tcltk.h"
 #include "window.h"
 #include "quirc.h"
