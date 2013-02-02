$NetBSD$

--- spunk/xsrc/screen.cc.orig	1996-11-07 18:06:58.000000000 +0000
+++ spunk/xsrc/screen.cc
@@ -21,6 +21,10 @@
 
 #include <string.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "../cont.h"
 #include "../winattr.h"
 #include "../environ.h"
