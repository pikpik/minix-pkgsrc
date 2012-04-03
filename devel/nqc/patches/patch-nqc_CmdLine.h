$NetBSD$

--- nqc/CmdLine.h.orig	2011-11-25 20:14:22.000000000 +0000
+++ nqc/CmdLine.h
@@ -18,7 +18,9 @@
 #define __CmdLine_h
 
 #include <stdlib.h>
-#include <vector.h>
+#include <vector>
+
+using std::vector;
 
 class CmdLine
 {
