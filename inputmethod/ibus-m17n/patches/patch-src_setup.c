$NetBSD$

--- src/setup.c.orig	2012-11-19 16:31:43.000000000 +0000
+++ src/setup.c
@@ -428,7 +428,7 @@ save_m17n_options (SetupDialog *dialog)
     gboolean retval = TRUE;
 
     if (!gtk_tree_model_get_iter_first (model, &iter))
-        return;
+        return FALSE;
 
     do {
         gtk_tree_model_get (model, &iter,
