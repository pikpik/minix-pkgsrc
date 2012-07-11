$NetBSD$

--- texk/web2c/luatexdir/luatex.c.orig	2011-05-19 05:39:15.000000000 +0000
+++ texk/web2c/luatexdir/luatex.c
@@ -32,7 +32,6 @@ const char *engine_name = "luatex";     
 #include <kpathsea/readable.h>
 #include <kpathsea/variable.h>
 #include <kpathsea/absolute.h>
-#include <kpathsea/recorder.h>
 #ifdef WIN32
 #include <kpathsea/concatn.h>
 #endif
