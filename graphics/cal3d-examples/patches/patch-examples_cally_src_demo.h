$NetBSD$

--- examples/cally/src/demo.h.orig	2003-09-08 03:03:32.000000000 +0000
+++ examples/cally/src/demo.h
@@ -11,6 +11,9 @@
 #ifndef DEMO_H
 #define DEMO_H
 
+#include <cstring>
+#include <strings.h>
+
 //----------------------------------------------------------------------------//
 // Includes                                                                   //
 //----------------------------------------------------------------------------//
