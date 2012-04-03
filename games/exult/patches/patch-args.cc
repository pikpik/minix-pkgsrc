$NetBSD$

--- args.cc.orig	2011-11-25 18:02:23.000000000 +0000
+++ args.cc
@@ -24,6 +24,7 @@
 #  include <iostream>
 #endif
 
+#include <cstdlib>
 #include "args.h"
 
 #ifndef UNDER_CE
