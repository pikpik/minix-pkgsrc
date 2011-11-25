$NetBSD$

--- tools/cmanip.cc.orig	2011-11-25 17:39:15.000000000 +0000
+++ tools/cmanip.cc
@@ -23,6 +23,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #ifndef ALPHA_LINUX_CXX
 #  include <cstdio>
+#  include <cstdlib>
 #endif
 #include "Configuration.h"
 #include <iostream>
