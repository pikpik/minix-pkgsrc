$NetBSD$

--- src/hyper/lex.c.orig	2011-07-07 19:04:11.000000000 +0000
+++ src/hyper/lex.c
@@ -62,6 +62,7 @@
 #include <ctype.h>
 #include <setjmp.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "debug.h"
 #include "sockio.h"
