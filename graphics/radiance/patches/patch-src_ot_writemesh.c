$NetBSD$

Use cpp in a valid fashion.

--- src/ot/writemesh.c~	2004-04-29 14:36:49.000000000 +0000
+++ src/ot/writemesh.c
@@ -11,6 +11,7 @@ static const char RCSid[] = "$Id: writem
 #include  "mesh.h"
 
 #ifdef putc_unlocked		/* avoid horrendous overhead of flockfile */
+#undef putc
 #define putc    putc_unlocked
 #endif
 
