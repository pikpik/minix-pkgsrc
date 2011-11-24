$NetBSD$

--- encfs/NameIO.cpp.orig	2011-11-24 00:21:19.000000000 +0000
+++ encfs/NameIO.cpp
@@ -20,6 +20,7 @@
 #include <rlog/rlog.h>
 
 #include <map>
+#include <cstring>
 
 using namespace std;
 using namespace rel;
