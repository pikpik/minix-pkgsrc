$NetBSD$

--- tagutils/tagutils.c.orig	2012-10-15 19:50:35.000000000 +0000
+++ tagutils/tagutils.c
@@ -40,6 +40,7 @@
 #ifdef HAVE_ICONV_H
 #include <iconv.h>
 #endif
+#include <libgen.h>
 
 #include <sqlite3.h>
 #include "tagutils.h"
