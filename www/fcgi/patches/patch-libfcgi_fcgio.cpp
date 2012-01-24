$NetBSD$

include <cstdio> for the EOF macro.

--- libfcgi/fcgio.cpp.orig	2012-01-24 02:50:08.663956233 +0000
+++ libfcgi/fcgio.cpp
@@ -23,6 +23,7 @@
 #endif
 
 #include <limits.h>
+#include <cstdio>
 #include "fcgio.h"
 
 using std::streambuf;
