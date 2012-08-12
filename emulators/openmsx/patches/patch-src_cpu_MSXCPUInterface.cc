$NetBSD$

--- src/cpu/MSXCPUInterface.cc.orig	2007-04-14 21:25:23.000000000 +0000
+++ src/cpu/MSXCPUInterface.cc
@@ -27,6 +27,7 @@
 #include <iomanip>
 #include <algorithm>
 #include <iostream>
+#include <cstring>
 
 using std::auto_ptr;
 using std::ostringstream;
