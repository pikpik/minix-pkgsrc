$NetBSD$

--- src/mathed/math_xdata.C.orig	2011-11-25 17:01:56.000000000 +0000
+++ src/mathed/math_xdata.C
@@ -9,7 +9,7 @@
 #include "Painter.h"
 #include "textpainter.h"
 #include "debug.h"
-
+#include <cstdlib>
 
 using std::max;
 using std::min;
