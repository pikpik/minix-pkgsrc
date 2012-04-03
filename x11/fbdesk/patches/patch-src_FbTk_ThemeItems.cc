$NetBSD$

--- src/FbTk/ThemeItems.cc.orig	2011-11-25 17:43:10.000000000 +0000
+++ src/FbTk/ThemeItems.cc
@@ -40,6 +40,8 @@
 #include "StringUtil.hh"
 
 #include <string>
+#include <cstdlib>
+#include <strings.h>
 #ifdef HAVE_CSTDIO
   #include <cstdio>
 #else
