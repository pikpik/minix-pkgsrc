$NetBSD$

Add missing header.

--- src/Wrappers/PosBasicBlock.h.orig	2006-08-20 20:41:04.000000000 +0000
+++ src/Wrappers/PosBasicBlock.h
@@ -33,7 +33,8 @@
 
 #include "../common/PosBlock.h"
 #include "BasicBlock.h"
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include "../common/UnexpectedException.h"
 class PosBasicBlock : public PosBlock
 {
