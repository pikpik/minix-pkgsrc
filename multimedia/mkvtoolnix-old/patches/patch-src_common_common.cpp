$NetBSD$

--- src/common/common.cpp.orig	2009-08-13 10:32:50.000000000 +0000
+++ src/common/common.cpp
@@ -15,6 +15,7 @@
 
 #include <boost/regex.hpp>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string>
 #ifdef SYS_WINDOWS
 # include <windows.h>
