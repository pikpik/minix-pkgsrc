$NetBSD$

--- src/common/socket/OW_SocketAddress.cpp.orig	2011-11-24 02:51:19.000000000 +0000
+++ src/common/socket/OW_SocketAddress.cpp
@@ -50,6 +50,7 @@ extern "C"
 #include <sys/param.h>
 #include <sys/utsname.h>
 #include <unistd.h>
+#include <string.h>
 #endif
 
 #include <errno.h>
