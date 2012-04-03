$NetBSD$

Add missing header.

--- src/TM/WosTupleIter.cpp.orig	2005-07-06 04:06:24.000000000 +0000
+++ src/TM/WosTupleIter.cpp
@@ -35,6 +35,7 @@
  */
 
 #include <string>
+#include <stdlib.h>
 #include <vector>
 
 #include "WosTuple.h"  //tuple representation of WOS projection
