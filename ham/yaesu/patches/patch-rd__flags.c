$NetBSD$

--- rd_flags.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ rd_flags.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-rd_flags(int fdSer) {
+void rd_flags(int fdSer) {
    int opcode, split_byte, n;
 
    opcode = 250;
