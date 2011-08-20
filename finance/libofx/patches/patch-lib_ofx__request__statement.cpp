$NetBSD$

Fix build with gcc-4.5.

--- lib/ofx_request_statement.cpp.orig	2007-10-28 03:01:38.000000000 +0000
+++ lib/ofx_request_statement.cpp
@@ -21,6 +21,7 @@
 #include <config.h>
 #endif
 
+#include <stdlib.h>
 #include <string>
 #include "libofx.h"
 #include "ofx_utilities.hh"
