$NetBSD$

--- src/widgets/desktop-widget.h.orig	2012-11-15 16:18:43.000000000 +0000
+++ src/widgets/desktop-widget.h
@@ -239,7 +239,7 @@ struct SPDesktopWidget {
 private:
     GtkWidget *tool_toolbox;
     GtkWidget *aux_toolbox;
-    GtkWidget *commands_toolbox,;
+    GtkWidget *commands_toolbox;
     GtkWidget *snap_toolbox;
 
     static void init(SPDesktopWidget *widget);
