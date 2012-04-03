$NetBSD$

Add missing header.

--- src/materialexps/PosAndEM.cpp.orig	2006-05-25 20:23:51.000000000 +0000
+++ src/materialexps/PosAndEM.cpp
@@ -32,6 +32,7 @@
  */
 #include "PosAndEM.h"
 #include "posand-support.h"
+#include <stdlib.h>
 
 PosAndEM::PosAndEM() {
 }
