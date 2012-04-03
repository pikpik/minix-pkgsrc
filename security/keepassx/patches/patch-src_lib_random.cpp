$NetBSD$

--- src/lib/random.cpp.orig	2011-11-24 01:44:17.000000000 +0000
+++ src/lib/random.cpp
@@ -21,6 +21,7 @@
 #include <fstream>
 #include <qdatetime.h>
 #include <qobject.h>
+#include <cstdlib>
 #include "random.h"
 using namespace std;
 
