$NetBSD$

--- src/common/OW_StackTrace.cpp.orig	2011-11-24 02:53:47.000000000 +0000
+++ src/common/OW_StackTrace.cpp
@@ -35,6 +35,7 @@
 #include "OW_config.h"
 #include "OW_StackTrace.hpp"
 
+#include <cstdlib>
 #ifdef OW_WIN32
 #include <iostream>	// for cerr
 namespace OW_NAMESPACE
