$NetBSD$

Use cpp in a valid fashion.

--- src/ot/writeoct.c~	2004-04-29 14:36:49.000000000 +0000
+++ src/ot/writeoct.c
@@ -14,6 +14,7 @@ static const char RCSid[] = "$Id: writeo
 #include  "oconv.h"
 
 #ifdef putc_unlocked		/* avoid horrendous overhead of flockfile */
+#undef putc
 #define putc    putc_unlocked
 #endif
 
