$NetBSD$

--- usecode/compiler/ucloc.cc.orig	2011-11-25 17:50:54.000000000 +0000
+++ usecode/compiler/ucloc.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 
 #include <iostream>
+#include <cstring>
 #include "ucloc.h"
 
 using std::strcmp;
