$NetBSD$

--- src/preproc/grn/main.cpp.orig	Mon Jul 11 11:23:19 2011
+++ src/preproc/grn/main.cpp
@@ -66,6 +66,7 @@
  * are used for text processing and g5-g7 are reserved.
  */
 
+#include <locale.h>
 
 #include "lib.h"
 
