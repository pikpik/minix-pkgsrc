$NetBSD$

--- compiler/FunctionDef.h.orig	2011-11-25 20:16:48.000000000 +0000
+++ compiler/FunctionDef.h
@@ -26,7 +26,8 @@
 #include "PListS.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class Symbol;
 class Stmt;
