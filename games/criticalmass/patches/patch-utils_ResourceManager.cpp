$NetBSD$

--- utils/ResourceManager.cpp.orig	2011-11-24 00:45:09.000000000 +0000
+++ utils/ResourceManager.cpp
@@ -15,6 +15,7 @@
 #include <iomanip>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <string.h>
 
 #include <Trace.hpp>
 #include <ResourceManager.hpp>
