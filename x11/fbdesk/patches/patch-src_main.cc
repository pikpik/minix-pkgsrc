$NetBSD$

--- src/main.cc.orig	2011-11-25 17:43:54.000000000 +0000
+++ src/main.cc
@@ -24,6 +24,8 @@
 #include "version.h"
 
 #include <iostream>
+#include <cstring>
+#include <cstdlib>
 #include <stdexcept>
 #include <signal.h>
 #include <sys/wait.h>
