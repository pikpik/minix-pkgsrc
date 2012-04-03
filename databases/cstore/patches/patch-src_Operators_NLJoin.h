$NetBSD$

Add missing header.

--- src/Operators/NLJoin.h.orig	2006-08-20 20:43:49.000000000 +0000
+++ src/Operators/NLJoin.h
@@ -43,7 +43,7 @@
 #include "../Wrappers/SMultiBlock.h"
 #include "../Wrappers/MultiBlock.h"
 #include <math.h>
-#include <hash_map.h>
+#include <hash_map>
 
 class NLJoin : public Operator {
 
