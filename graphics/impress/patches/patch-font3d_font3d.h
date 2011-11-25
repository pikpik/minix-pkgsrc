$NetBSD$

--- font3d/font3d.h.orig	2011-11-25 18:28:29.000000000 +0000
+++ font3d/font3d.h
@@ -31,7 +31,8 @@
 #ifndef __FONT3D_H__
 #define __FONT3D_H__
 
-#include <fstream.h>
+#include <fstream>
+#include <cstring>
 #include <stddef.h>
 
 #define RIGHT_HANDED          0
