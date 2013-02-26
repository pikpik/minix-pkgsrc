$NetBSD$

--- libffmpegthumbnailer/pngwriter.cpp.orig	2013-02-25 17:13:07.000000000 +0000
+++ libffmpegthumbnailer/pngwriter.cpp
@@ -17,6 +17,7 @@
 #include "pngwriter.h"
 #include <stdexcept>
 #include <cassert>
+#include <cstring>
 
 using namespace std;
 
