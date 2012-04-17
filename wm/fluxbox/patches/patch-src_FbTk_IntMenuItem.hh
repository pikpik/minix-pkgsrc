$NetBSD$

--- src/FbTk/IntMenuItem.hh.orig	2012-03-01 15:31:11.000000000 +0000
+++ src/FbTk/IntMenuItem.hh
@@ -26,7 +26,7 @@
 
 namespace FbTk {
 
-class Accessor<class T>;
+template<> class Accessor<class T>;
 
 /// Changes an resource integer value between min and max
 class IntMenuItem: public FbTk::MenuItem {
