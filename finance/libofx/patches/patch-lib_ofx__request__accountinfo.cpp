$NetBSD$

Fix build with gcc-4.5.

--- lib/ofx_request_accountinfo.cpp.orig	2007-10-28 03:01:38.000000000 +0000
+++ lib/ofx_request_accountinfo.cpp
@@ -22,6 +22,7 @@
 #endif
 
 #include <string>
+#include <stdlib.h>
 #include "libofx.h"
 #include "ofx_request_accountinfo.hh"
 
