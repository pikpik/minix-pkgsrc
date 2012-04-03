$NetBSD$

--- src/classes/dotImporter.cc.orig	2011-11-24 01:07:22.000000000 +0000
+++ src/classes/dotImporter.cc
@@ -1,5 +1,6 @@
 #include "dotImporter.h"
 #include <string.h>
+#include <stdlib.h>
 #include <gtk/gtk.h>
 #include "../interface.h"
 
