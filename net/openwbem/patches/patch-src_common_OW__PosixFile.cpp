$NetBSD$

--- src/common/OW_PosixFile.cpp.orig	2011-11-24 02:53:14.000000000 +0000
+++ src/common/OW_PosixFile.cpp
@@ -36,6 +36,7 @@
 #include "OW_config.h"
 #include "OW_File.hpp"
 
+#include <string.h>
 #ifdef OW_WIN32
 	#include <io.h>
 	#include <stdlib.h>
