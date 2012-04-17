$NetBSD$

--- src/FbTk/Menu.hh.orig	2012-03-01 15:15:51.000000000 +0000
+++ src/FbTk/Menu.hh
@@ -38,10 +38,10 @@
 
 namespace FbTk {
 
-class Command<class T>;
+template <> class Command<class T>;
 class MenuItem;
 class ImageControl;
-class RefCount<class T>;
+template <> class RefCount<class T>;
 
 ///   Base class for menus
 class Menu: public FbTk::EventHandler, FbTk::FbWindowRenderer,
