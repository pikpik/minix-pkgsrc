$NetBSD$

--- FatController.cpp.orig	2011-11-25 17:13:02.000000000 +0000
+++ FatController.cpp
@@ -44,6 +44,8 @@
 #include <fstream>
 #include <sys/time.h>
 #include <sys/poll.h>
+#include <cstdlib>
+#include <cstring>
 
 #ifdef __GCCVER3
     #include <istream>
