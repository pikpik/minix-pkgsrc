$NetBSD$

--- src/common/OW_LogMessagePatternFormatter.cpp.orig	2011-11-24 02:52:41.000000000 +0000
+++ src/common/OW_LogMessagePatternFormatter.cpp
@@ -44,6 +44,7 @@
 #include "OW_ThreadImpl.hpp"
 
 #include <vector>
+#include <climits>
 #include <cstdlib> // for strtol
 
 extern "C"
