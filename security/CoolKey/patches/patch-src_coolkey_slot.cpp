$NetBSD$

--- src/coolkey/slot.cpp.orig	2011-11-25 17:09:33.000000000 +0000
+++ src/coolkey/slot.cpp
@@ -31,6 +31,8 @@
 
 #include "machdep.h"
 
+#include <memory>
+
 #define MIN(x, y) ((x) < (y) ? (x) : (y))
 
 using std::auto_ptr;
