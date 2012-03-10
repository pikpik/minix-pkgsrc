$NetBSD$

Fix build with gcc 4.6

--- src/WordList.cpp.orig	2008-04-30 08:26:40.000000000 +0000
+++ src/WordList.cpp
@@ -9,6 +9,7 @@
  */
 
 #include <config.h>
+#include <cstddef>
 
 #include "WordList.h"
 
