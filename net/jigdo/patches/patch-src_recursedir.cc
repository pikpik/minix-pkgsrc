$NetBSD$

--- src/recursedir.cc.orig	2011-11-25 18:40:56.000000000 +0000
+++ src/recursedir.cc
@@ -32,6 +32,7 @@
 #include <recursedir.hh>
 
 #include <iostream>
+#include <cstring>
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/types.h>
