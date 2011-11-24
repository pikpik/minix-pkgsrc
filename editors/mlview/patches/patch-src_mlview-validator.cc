$NetBSD$

--- src/mlview-validator.cc.orig	2011-11-24 02:26:56.000000000 +0000
+++ src/mlview-validator.cc
@@ -25,6 +25,7 @@
 
 #include "mlview-validator.h"
 #include "mlview-safe-ptr-utils.h"
+#include <memory>
 
 #define MESSAGE_LINE_LENGTH 55
 namespace mlview
