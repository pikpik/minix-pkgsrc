$NetBSD$

--- src/util/configfile.cc.orig	2011-11-25 18:41:22.000000000 +0000
+++ src/util/configfile.cc
@@ -18,6 +18,7 @@
 
 #include <iostream>
 #include <fstream>
+#include <cstring>
 
 #include <configfile.hh>
 #include <string.hh>
