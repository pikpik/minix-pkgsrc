$NetBSD$

--- lib/libxview/textsw/txt_sel.c.orig	2012-11-14 16:32:32.000000000 +0000
+++ lib/libxview/textsw/txt_sel.c
@@ -588,7 +588,7 @@ textsw_mouseless_select_event(view, ie, 
 	return is_select_event;
 }
 
-static int
+static void
 update_selection(view, ie)
     Textsw_view_handle view;
     register Event *ie;
