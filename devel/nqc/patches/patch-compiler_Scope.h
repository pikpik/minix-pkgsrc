$NetBSD$

--- compiler/Scope.h.orig	2011-11-25 20:13:30.000000000 +0000
+++ compiler/Scope.h
@@ -30,7 +30,9 @@
 #include "AutoFree.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+
+using std::vector;
 
 class Symbol;
 
