$NetBSD$

- declare void functions void
- use c89

--- te_fxstub.c~	1993-08-05 22:29:34.000000000 +0000
+++ te_fxstub.c
@@ -10,7 +10,7 @@
 
 #include "te_defs.h"
 
-te_fx()
+VOID te_fx(void)
 {
 	ERROR(E_IFC);
 }
