$NetBSD$

imlib2 patch from suse.

--- image/xloadimage.h.orig	2007-12-28 20:31:26.000000000 +0000
+++ image/xloadimage.h
@@ -16,7 +16,7 @@
 #include "options.h"
 
 #ifdef USE_IMLIB
-#include <Imlib.h>
+#include <Imlib2.h>
 #endif
 
 /* image name and option structure used when processing arguments
