$NetBSD$

--- game.cc.orig	2011-11-24 01:12:02.000000000 +0000
+++ game.cc
@@ -37,6 +37,7 @@
 #include <sys/stat.h> 
 #include <unistd.h>
 #include <fcntl.h>
+#include <stdlib.h>
 
 #ifdef _
 #  undef _
