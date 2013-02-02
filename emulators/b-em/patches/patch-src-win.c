$NetBSD: patch-src-win.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/win.c.orig	2012-05-22 11:39:06.000000000 +0000
+++ src/win.c
@@ -345,6 +345,7 @@ int WINAPI WinMain (HINSTANCE hThisInsta
         get_executable_name(exedir, 511);
         p = get_filename(exedir);
         p[0] = 0;
+        strcpy(exedir, "@BEMDATADIR@");
 
         config_load();
 
