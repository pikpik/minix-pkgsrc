$NetBSD$

--- src/video/MemoryOps.cc.orig	2011-11-24 02:47:07.000000000 +0000
+++ src/video/MemoryOps.cc
@@ -10,6 +10,7 @@
 #include <map>
 #include <cassert>
 #include <cstdlib>
+#include <cstring>
 
 namespace openmsx {
 
