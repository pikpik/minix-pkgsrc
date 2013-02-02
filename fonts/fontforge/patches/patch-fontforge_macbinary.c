$NetBSD$

Fix OS X headers.

--- fontforge/macbinary.c.orig	2012-11-22 16:48:27.000000000 +0000
+++ fontforge/macbinary.c
@@ -37,7 +37,7 @@
 #include "psfont.h"
 #if __Mac
 # include <ctype.h>
-# include </Developer/Headers/FlatCarbon/Files.h>
+#include <CoreServices/CoreServices.h>
 #else
 # include <utype.h>
 #undef __Mac
