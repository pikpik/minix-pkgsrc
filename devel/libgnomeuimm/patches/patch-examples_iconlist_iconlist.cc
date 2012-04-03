$NetBSD$

--- examples/iconlist/iconlist.cc.orig	2012-01-18 23:41:46.000000000 +0000
+++ examples/iconlist/iconlist.cc
@@ -58,6 +58,7 @@ IconWindow::IconWindow ()
     show_all_children ();
 }
  
+int
 main (int argc, char *argv[])
 {
    Gnome::Main kit ("Iconlist", "0.0.0", Gnome::UI::module_info_get(), argc, argv);
