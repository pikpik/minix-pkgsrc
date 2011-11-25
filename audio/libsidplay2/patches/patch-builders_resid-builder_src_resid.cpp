$NetBSD$

--- builders/resid-builder/src/resid.cpp.orig	2011-11-25 19:35:44.000000000 +0000
+++ builders/resid-builder/src/resid.cpp
@@ -21,6 +21,7 @@
 #ifdef HAVE_EXCEPTIONS
 #   include <new>
 #endif
+#include <cstring>
 
 #include "resid.h"
 #include "resid-emu.h"
