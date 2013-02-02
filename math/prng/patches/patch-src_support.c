$NetBSD$

--- src/support.c.orig	2012-10-30 20:02:12.000000000 +0000
+++ src/support.c
@@ -449,7 +449,7 @@ for(mask = ~0; mask; mask >>= 1)   /* ~0
 		}
 }
 
-#ifndef __cplusplus
+#if 0
 /* 
  * Modular Multiplication. Uses the precalculated values from mult_mod_setup.
  *
