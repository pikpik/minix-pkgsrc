$NetBSD$

--- src/celestia/url.cpp.orig	2011-11-25 16:35:25.000000000 +0000
+++ src/celestia/url.cpp
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <cstring>
 #include <string>
 #include <stdio.h>
 #include "celestiacore.h"
