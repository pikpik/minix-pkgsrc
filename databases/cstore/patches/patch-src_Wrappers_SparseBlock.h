$NetBSD$

Add missing header.

--- src/Wrappers/SparseBlock.h.orig	2006-09-07 23:39:00.000000000 +0000
+++ src/Wrappers/SparseBlock.h
@@ -37,7 +37,7 @@
 #include "Type2Block.h"
 #include "../common/PosBlock.h"
 #include "CodingException.h"
-#include <iostream.h>
+#include <iostream>
 
 class SparseBlock : public MultiBlock
 {
