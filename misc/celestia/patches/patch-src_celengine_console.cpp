$NetBSD: patch-src_celengine_console.cpp,v 1.1 2011/11/25 22:08:30 joerg Exp $

--- src/celengine/console.cpp.orig	2005-07-19 20:30:54.000000000 +0000
+++ src/celengine/console.cpp
@@ -9,6 +9,7 @@
 
 #include <cstdarg>
 #include <cstdio>
+#include <cstring>
 #include <cassert>
 #include "celutil/utf8.h"
 #include "gl.h"
