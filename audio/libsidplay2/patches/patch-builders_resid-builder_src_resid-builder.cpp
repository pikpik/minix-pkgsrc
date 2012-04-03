$NetBSD$

--- builders/resid-builder/src/resid-builder.cpp.orig	2011-11-25 19:35:59.000000000 +0000
+++ builders/resid-builder/src/resid-builder.cpp
@@ -42,6 +42,7 @@
 #ifdef HAVE_EXCEPTIONS
 #   include <new>
 #endif
+#include <cstring>
 
 #include "resid.h"
 #include "resid-emu.h"
