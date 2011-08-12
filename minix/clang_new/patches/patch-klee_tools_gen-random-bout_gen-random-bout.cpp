$NetBSD$

--- klee/tools/gen-random-bout/gen-random-bout.cpp.orig	Thu Aug 11 01:14:44 2011
+++ klee/tools/gen-random-bout/gen-random-bout.cpp
@@ -9,7 +9,7 @@
 
 #include "klee/Internal/ADT/KTest.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__minix)
 #define stat64 stat
 #endif
 
