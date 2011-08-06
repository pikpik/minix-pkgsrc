$NetBSD$

Fix for compilation failure on Linux
--- tx/TXImage.cxx.orig	2006-05-15 16:56:20.000000000 +0000
+++ tx/TXImage.cxx
@@ -21,6 +21,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <strings.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
