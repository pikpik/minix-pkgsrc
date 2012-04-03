$NetBSD$

Add missing header.

--- src/weapon.cpp.orig	2005-10-03 05:42:21.000000000 +0000
+++ src/weapon.cpp
@@ -5,6 +5,7 @@
 #include "vc6.h" // Fixes things if you're using VC6, does nothing if otherwise
 
 #include <string>
+#include <string.h>
 
 #include "weapon.h"
 
