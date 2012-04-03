$NetBSD$

--- src/result.cxx.orig	2011-11-24 00:13:16.000000000 +0000
+++ src/result.cxx
@@ -18,6 +18,7 @@
 #include "pqxx/compiler.h"
 
 #include <stdexcept>
+#include <cstdlib>
 
 #include "libpq-fe.h"
 
