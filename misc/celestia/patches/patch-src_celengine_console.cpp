$NetBSD$

--- src/celengine/console.cpp.orig	2011-11-25 16:12:42.000000000 +0000
+++ src/celengine/console.cpp
@@ -9,6 +9,7 @@
 
 #include <cstdarg>
 #include <cstdio>
+#include <cstring>
 #include <cassert>
 #include "celutil/utf8.h"
 #include "gl.h"
