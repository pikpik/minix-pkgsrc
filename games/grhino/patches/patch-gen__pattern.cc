$NetBSD$

--- gen_pattern.cc.orig	2011-11-24 01:16:59.000000000 +0000
+++ gen_pattern.cc
@@ -23,6 +23,7 @@
 #include <fstream>
 #include <sstream>
 
+#include <string.h>
 #include <math.h>
 #include <unistd.h>
 #include <fcntl.h>
