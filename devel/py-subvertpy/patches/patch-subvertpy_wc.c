$NetBSD$

# PR 45649
--- subvertpy/wc.c.orig	2011-10-26 00:23:01.000000000 +0000
+++ subvertpy/wc.c
@@ -27,6 +27,7 @@
 
 #include "util.h"
 #include "editor.h"
+#include "wc.h"
 
 #ifndef T_BOOL
 #define T_BOOL T_BYTE
