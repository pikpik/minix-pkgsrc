$NetBSD$

--- lib/libxview/panel/p_utl.c.orig	2012-11-14 14:26:03.000000000 +0000
+++ lib/libxview/panel/p_utl.c
@@ -775,7 +775,7 @@ panel_nullproc()
 }
 
 
-Pkg_private
+Pkg_private void
 panel_free_choices(choices, first, last)
     Panel_image    *choices;
     int             first, last;
