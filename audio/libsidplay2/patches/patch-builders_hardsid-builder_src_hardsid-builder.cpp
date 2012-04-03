$NetBSD$

--- builders/hardsid-builder/src/hardsid-builder.cpp.orig	2012-02-04 09:37:28.328184353 +0000
+++ builders/hardsid-builder/src/hardsid-builder.cpp
@@ -47,6 +47,7 @@
  ***************************************************************************/
 
 #include <stdio.h>
+#include <cstring>
 #include "config.h"
 
 #ifdef HAVE_EXCEPTIONS
