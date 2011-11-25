$NetBSD$

--- src/backup.cpp.orig	2011-11-25 14:59:05.000000000 +0000
+++ src/backup.cpp
@@ -26,6 +26,7 @@
 #include "tools.h"
 #include "formatimporter.h" // To move a folder
 
+#include <cstdlib>
 #include <qhbox.h>
 #include <qvbox.h>
 #include <qlayout.h>
