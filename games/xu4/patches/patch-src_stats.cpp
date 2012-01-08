$NetBSD$

Add missing header.

--- src/stats.cpp.orig	2005-08-24 05:55:35.000000000 +0000
+++ src/stats.cpp
@@ -18,6 +18,7 @@
 #include "spell.h"
 #include "tile.h"
 #include "weapon.h"
+#include <string.h>
 
 extern bool verbose;
 
