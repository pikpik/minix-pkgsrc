$NetBSD$

--- stralloc.h.orig	2013-02-25 16:49:07.000000000 +0000
+++ stralloc.h
@@ -1,6 +1,9 @@
 #ifndef STRALLOC_H
 #define STRALLOC_H
 
+#include <stdlib.h>
+#include <unistd.h>
+
 #include "gen_alloc.h"
 
 GEN_ALLOC_typedef(stralloc,char,s,len,a)
