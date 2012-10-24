$NetBSD$

--- step.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ step.c
@@ -1,8 +1,6 @@
-extern main();
-extern flag_data_return[];
-extern outport();
+#include "yaesu.h"
 
-step(int fdSer) {
+void step(int fdSer) {
     int opcode, stepper, param_byte, up_down, tx_mode;
     char step_decide;
 
