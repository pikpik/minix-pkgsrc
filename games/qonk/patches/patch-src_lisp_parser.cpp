$NetBSD$

--- src/lisp/parser.cpp.orig	2011-12-05 21:38:05.000000000 +0000
+++ src/lisp/parser.cpp
@@ -22,6 +22,7 @@
 #include <fstream>
 
 #include <cassert>
+#include <cstring>
 
 #include "parser.hpp"
 #include "lisp.hpp"
