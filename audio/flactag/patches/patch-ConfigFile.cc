$NetBSD$

--- ConfigFile.cc.orig	2008-12-16 11:20:56.000000000 +0000
+++ ConfigFile.cc
@@ -25,6 +25,7 @@
 ----------------------------------------------------------------------------*/
 
 #include "ConfigFile.h"
+#include <cstdio>
 
 CConfigFile::CConfigFile()
 {
