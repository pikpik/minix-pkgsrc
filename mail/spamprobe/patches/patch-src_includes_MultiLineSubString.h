$NetBSD$

--- src/includes/MultiLineSubString.h.orig	2011-12-06 16:26:43.000000000 +0000
+++ src/includes/MultiLineSubString.h
@@ -32,6 +32,7 @@
 #define _MultiLineSubString_h
 
 #include "AbstractMultiLineString.h"
+#include <climits>
 
 class MultiLineSubString : public AbstractMultiLineString
 {
