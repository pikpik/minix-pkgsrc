$NetBSD$

--- libs/auxfun/image.cpp.orig	2013-03-04 13:54:30.000000000 +0000
+++ libs/auxfun/image.cpp
@@ -7,6 +7,7 @@
 #include <zlib.h>
 #include <png.h>
 #include <stdlib.h>
+#include <string.h>
 #ifdef _MSC_VER
 #define _USE_MATH_DEFINES 1
 #include <math.h>
