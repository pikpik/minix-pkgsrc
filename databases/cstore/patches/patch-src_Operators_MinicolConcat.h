$NetBSD$

Add missing header.

--- src/Operators/MinicolConcat.h.orig	2006-02-25 20:26:25.000000000 +0000
+++ src/Operators/MinicolConcat.h
@@ -5,7 +5,7 @@
 #include "../common/MinicolBlock.h"
 #include "../common/UnexpectedException.h"
 #include <stack>
-#include <list.h>
+#include <list>
 
 class MinicolConcat : public Operator
 {
