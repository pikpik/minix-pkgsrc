$NetBSD$

--- bright.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ bright.c
@@ -1,7 +1,6 @@
-extern main();
-extern opcode();
+#include "yaesu.h"
 
-bright(int fdSer) {
+void bright(int fdSer) {
   int opcode, bright_level;
   opcode = 0x0f8;
   printf("Enter brightness level: 0..7 [brightest] -> ");
