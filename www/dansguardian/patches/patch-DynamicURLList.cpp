$NetBSD$

--- DynamicURLList.cpp.orig	2011-11-25 17:14:23.000000000 +0000
+++ DynamicURLList.cpp
@@ -23,6 +23,7 @@
 #include "OptionContainer.hpp"
 #include <sys/stat.h>
 #include <sys/time.h>
+#include <cstring>
 
 extern OptionContainer o;
 extern bool isDaemonised;
