$NetBSD$

--- src/file/ZipFileAdapter.cc.orig	2011-11-24 02:43:55.000000000 +0000
+++ src/file/ZipFileAdapter.cc
@@ -3,6 +3,7 @@
 #include <zlib.h>
 #include "ZipFileAdapter.hh"
 #include "FileException.hh"
+#include <cstdlib>
 
 namespace openmsx {
 
