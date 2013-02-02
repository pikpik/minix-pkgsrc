$NetBSD$

Fix for GCC 4.7.
--- src/transport.h.orig	2011-06-11 13:17:44.000000000 +0000
+++ src/transport.h
@@ -22,6 +22,7 @@
 #define TRANSPORT_H
 #include <iostream>
 #include <string>
+#include "unistd.h"
 #include "gloox/tag.h"
 #include "gloox/siprofileft.h"
 #include "parser.h"
