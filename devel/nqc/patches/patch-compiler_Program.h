$NetBSD$

--- compiler/Program.h.orig	2011-11-25 20:13:40.000000000 +0000
+++ compiler/Program.h
@@ -41,7 +41,7 @@
 #include "VarAllocator.h"
 #endif
 
-#include <vector.h>
+#include <vector>
 
 class Fragment;
 class FunctionDef;
