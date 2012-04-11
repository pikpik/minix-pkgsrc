$NetBSD$

--- libstdc++-v3/config/io/basic_file_stdio.cc.orig	Thu Apr  9 23:23:07 2009
+++ libstdc++-v3/config/io/basic_file_stdio.cc
@@ -27,6 +27,10 @@
 // ISO C++ 14882: 27.8  File-based streams
 //
 
+#ifndef _POSIX_SOURCE
+#define _POSIX_SOURCE 1
+#endif
+
 #include <bits/basic_file.h>
 #include <fcntl.h>
 #include <errno.h>
