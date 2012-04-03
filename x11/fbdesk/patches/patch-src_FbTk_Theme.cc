$NetBSD$

--- src/FbTk/Theme.cc.orig	2011-11-25 17:39:29.000000000 +0000
+++ src/FbTk/Theme.cc
@@ -29,6 +29,7 @@
 #include "FileUtil.hh"
 #include "Image.hh"
 
+#include <algorithm>
 #ifdef HAVE_CSTDIO
   #include <cstdio>
 #else
