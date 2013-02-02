$NetBSD$

--- spunk/str.cc.orig	1996-12-01 11:23:50.000000000 +0000
+++ spunk/str.cc
@@ -31,6 +31,7 @@
 #include "stream.h"
 #include "streamid.h"
 
+#undef CS
 
 
 // Register class String
