$NetBSD$

--- account.c.orig	2013-03-01 13:50:44.000000000 +0000
+++ account.c
@@ -74,7 +74,7 @@ void cb_map_account_dialog();
 /*
  * create_account_dialog - Creates the "Get Account" dialog.
  */
-create_account_dialog()
+static void create_account_dialog(void)
 {
     static int initialized = False;
     int i;
