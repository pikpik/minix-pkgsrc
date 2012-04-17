$NetBSD$

--- src/FbTk/BoolMenuItem.hh.orig	2012-03-01 15:31:36.000000000 +0000
+++ src/FbTk/BoolMenuItem.hh
@@ -26,7 +26,7 @@
 
 namespace FbTk {
 
-class Accessor<class T>;
+template<> class Accessor<class T>;
 
 /// a bool menu item
 class BoolMenuItem: public FbTk::MenuItem {
