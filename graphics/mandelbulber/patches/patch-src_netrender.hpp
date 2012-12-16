$NetBSD$

* Fix build on *BSD

--- src/netrender.hpp.orig	2012-12-02 16:22:54.000000000 +0000
+++ src/netrender.hpp
@@ -23,6 +23,8 @@
 	#include <netdb.h>
 #endif
 
+#include <netinet/in.h>
+
 #include <errno.h>
 #include <unistd.h>
 #include <vector>
