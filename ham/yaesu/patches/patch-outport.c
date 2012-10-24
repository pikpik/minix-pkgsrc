$NetBSD$

--- outport.c.orig	2012-10-21 10:06:08.000000000 +0000
+++ outport.c
@@ -1,6 +1,6 @@
-extern main();
+#include "yaesu.h"
 
-outport(int fdSer, int one, int two, int three, int four, int opcode) {
+void outport(int fdSer, int one, int two, int three, int four, int opcode) {
     
     write(fdSer,&one,1);
     write(fdSer,&two,1);
