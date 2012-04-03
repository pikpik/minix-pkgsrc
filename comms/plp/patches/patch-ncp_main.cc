$NetBSD$

Update for C++ changes.

--- ncp/main.cc.orig	1999-04-12 21:38:15.000000000 +0000
+++ ncp/main.cc
@@ -21,7 +21,8 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <stream.h>
+#include <iostream>
+using namespace std;
 #include <stdlib.h>
 
 #include "../defaults.h"
