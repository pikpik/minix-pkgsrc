$NetBSD$

Include correct config.h as there might be other impostors wandering around.

--- src/ssl/gadgets.cc.orig	2011-07-20 10:55:12.000000000 +0000
+++ src/ssl/gadgets.cc
@@ -3,5 +3,5 @@
  */
 
-#include "config.h"
+#include "include/config.h"
 #include "ssl/gadgets.h"
 
