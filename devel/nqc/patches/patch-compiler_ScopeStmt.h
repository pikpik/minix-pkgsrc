$NetBSD$

--- compiler/ScopeStmt.h.orig	2011-11-25 20:17:18.000000000 +0000
+++ compiler/ScopeStmt.h
@@ -21,8 +21,6 @@
 #include "Stmt.h"
 #endif
 
-#include <vector.h>
-
 class ScopeStmt : public ChainStmt
 {
 public:
