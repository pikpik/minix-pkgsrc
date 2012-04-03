$NetBSD$

--- daapd.cc.orig	2012-01-17 00:33:56.007883523 +0100
+++ daapd.cc	2012-01-17 00:37:49.469248794 +0100
@@ -29,6 +29,7 @@
 #include <cstring>
 #include <cassert>
 
+#include <limits.h>
 #include <unistd.h>
 #include <errno.h>
 #include <sys/time.h>
