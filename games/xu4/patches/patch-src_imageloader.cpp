$NetBSD$

Add missing header.

--- src/imageloader.cpp.orig	2004-08-19 08:03:52.000000000 +0000
+++ src/imageloader.cpp
@@ -7,6 +7,7 @@
 #include "debug.h"
 #include "image.h"
 #include "imageloader.h"
+#include <stdlib.h>
 
 std::map<std::string, ImageLoader *> *ImageLoader::loaderMap = NULL;
 
