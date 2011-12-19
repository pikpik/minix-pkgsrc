$NetBSD$

Add missing include.

--- src/operator.cc.orig	2005-09-07 13:34:23.000000000 +0000
+++ src/operator.cc
@@ -1,4 +1,5 @@
 #include <iostream>
+#include <typeinfo>
 
 #include "operator.h"
 #include "errors.h"
