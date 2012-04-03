$NetBSD$

--- src/weeport.cc.orig	2011-11-22 19:09:39.000000000 +0000
+++ src/weeport.cc
@@ -24,5 +24,5 @@
 ****************************************************************************/
 
-#include <iostream.h>
+#include <iostream>
 
 #include <stdlib.h>
@@ -49,4 +49,6 @@
 #include "weeport.hh"
 
+using namespace std;
+
 /*--------------------------------------------------------------------
   Class : Weeport
