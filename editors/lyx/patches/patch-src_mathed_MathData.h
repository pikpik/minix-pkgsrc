$NetBSD$

Fix build with gcc 4.6

--- src/mathed/MathData.h.orig	2010-01-20 02:10:29.000000000 +0000
+++ src/mathed/MathData.h
@@ -15,6 +15,7 @@
 #ifndef MATH_DATA_H
 #define MATH_DATA_H
 
+#include <cstddef>
 #include "Dimension.h"
 #include "MathAtom.h"
 
