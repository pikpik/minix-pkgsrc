$NetBSD$

Include the abs() implementation which takes a 'double' argument.

--- kate/part/katebuffer.cpp.orig	Thu Aug  2 10:37:49 2012
+++ kate/part/katebuffer.cpp	Thu Aug  2 11:35:57 2012
@@ -21,6 +21,8 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
+#include <cmath>
+
 #include "katebuffer.h"
 #include "katebuffer.moc"
 
