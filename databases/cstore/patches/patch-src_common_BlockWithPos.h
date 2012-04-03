$NetBSD$

Add missing header.

--- src/common/BlockWithPos.h.orig	2006-08-20 20:41:49.000000000 +0000
+++ src/common/BlockWithPos.h
@@ -36,7 +36,8 @@
 
 #include "BlockPosNonContig.h"
 #include "PosBlock.h"
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 class BlockWithPos : public BlockPosNonContig
 {
