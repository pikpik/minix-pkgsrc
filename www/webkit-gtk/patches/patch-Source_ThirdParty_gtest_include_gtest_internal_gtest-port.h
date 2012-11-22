$NetBSD$

--- Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h.orig	2012-04-22 23:26:47.000000000 +0000
+++ Source/ThirdParty/gtest/include/gtest/internal/gtest-port.h
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
