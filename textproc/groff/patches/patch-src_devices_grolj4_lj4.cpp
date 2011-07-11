$NetBSD$

--- src/devices/grolj4/lj4.cpp.orig	Mon Jul 11 11:27:29 2011
+++ src/devices/grolj4/lj4.cpp
@@ -32,6 +32,8 @@ X command to specify inline escape sequence (how to sp
 X command to include bitmap graphics
 */
 
+#include <locale.h>
+
 #include "driver.h"
 #include "nonposix.h"
 
