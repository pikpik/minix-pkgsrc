$NetBSD$

--- password.c.orig	2013-03-01 14:03:13.000000000 +0000
+++ password.c
@@ -155,7 +155,7 @@ char *password;
 /*
  * create_password_dialog - Create dialog that prompts user for password.
  */
-create_password_dialog()
+static void create_password_dialog(void)
 {
     static int initialized = False;
     int i;
