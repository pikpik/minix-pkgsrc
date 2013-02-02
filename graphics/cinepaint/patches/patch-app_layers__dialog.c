$NetBSD$

--- app/layers_dialog.c.orig	2012-07-03 13:55:55.000000000 +0000
+++ app/layers_dialog.c
@@ -2769,7 +2769,7 @@ layer_widget_preview_redraw (LayerWidget
 # ifdef DEBUG
     printf("%s:%d %s() wrong data or widget\n", __FILE__,__LINE__,__func__);
 # endif
-    return FALSE;
+    return;
   }
 
 
