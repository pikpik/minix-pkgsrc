$NetBSD$

--- file.cpp.orig	2011-11-23 16:45:41.000000000 +0000
+++ file.cpp
@@ -1,3 +1,4 @@
+#include <string.h>
 #include "file.h"
 
 File::File(Memory *memory, Option *option)
