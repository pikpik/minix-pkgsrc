$NetBSD$

--- lib/libxview/frame/fm_display.c.orig	2012-11-14 14:10:46.000000000 +0000
+++ lib/libxview/frame/fm_display.c
@@ -524,7 +524,7 @@ frame_kbd_done(frame_public, sw)
 }
 
 /* ARGSUSED */
-Pkg_private
+Pkg_private void
 frame_set_color(frame, fg, bg)
     Frame_class_info *frame;
     XColor *fg;
