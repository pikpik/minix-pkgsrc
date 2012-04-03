$NetBSD$

--- src/commands/Completer.cc.orig	2011-11-24 02:40:18.000000000 +0000
+++ src/commands/Completer.cc
@@ -6,6 +6,7 @@
 #include "FileOperations.hh"
 #include "ReadDir.hh"
 #include <algorithm>
+#include <strings.h>
 
 using std::vector;
 using std::string;
