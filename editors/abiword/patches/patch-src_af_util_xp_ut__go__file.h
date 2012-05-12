$NetBSD$

Fix build with glib-2.32.

--- src/af/util/xp/ut_go_file.h.orig	2009-08-27 13:27:10.000000000 +0000
+++ src/af/util/xp/ut_go_file.h
@@ -31,7 +31,6 @@
 
 #include <glib.h>
 #include <gsf/gsf.h>
-#include <glib/gerror.h>
 #include <time.h>
 
 G_BEGIN_DECLS
