$NetBSD$

--- rlog/RLogChannel.cpp.orig	2011-11-22 17:34:38.000000000 +0000
+++ rlog/RLogChannel.cpp
@@ -17,6 +17,7 @@
  */
 		                                                                                
 
+#include <cstring>
 #include "RLogChannel.h"
 #include "rlog.h"
 #include "Lock.h"
