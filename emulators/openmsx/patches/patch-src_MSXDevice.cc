$NetBSD$

--- src/MSXDevice.cc.orig	2007-04-14 21:25:22.000000000 +0000
+++ src/MSXDevice.cc
@@ -11,6 +11,7 @@
 #include <set>
 #include <algorithm>
 #include <cassert>
+#include <cstring>
 
 using std::string;
 using std::vector;
