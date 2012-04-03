$NetBSD$

--- main.cc.orig	2011-11-25 13:56:32.000000000 +0000
+++ main.cc
@@ -6,6 +6,7 @@
  */
  
 #include "aewm.hh"
+#include <cstring>
 
 void forkExec(char *cmd)
 {
