$NetBSD$

Fix build with gcc 4.6

--- src/mathed/InsetMath.h.orig	2010-12-29 15:36:35.000000000 +0000
+++ src/mathed/InsetMath.h
@@ -13,6 +13,7 @@
 #ifndef MATH_INSET_H
 #define MATH_INSET_H
 
+#include <cstddef>
 #include "MathData.h"
 
 #include "insets/Inset.h"
