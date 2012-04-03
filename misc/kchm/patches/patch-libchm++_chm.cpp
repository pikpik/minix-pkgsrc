$NetBSD$

--- libchm++/chm.cpp.orig	2011-11-24 01:25:08.000000000 +0000
+++ libchm++/chm.cpp
@@ -5,6 +5,7 @@
 #include <map>
 #include <algorithm>
 #include <cassert>
+#include <cstring>
 
 #include "chmxx.h"
 #include "chm_lib.h"
