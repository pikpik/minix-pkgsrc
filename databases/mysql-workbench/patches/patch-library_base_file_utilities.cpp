$NetBSD$

--- library/base/file_utilities.cpp.orig	2012-08-09 20:56:59.000000000 +0000
+++ library/base/file_utilities.cpp
@@ -32,6 +32,9 @@
 #include <fcntl.h>
 #include <sys/file.h>
 #endif
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 
 namespace base {
   
