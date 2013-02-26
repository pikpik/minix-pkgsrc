$NetBSD$

--- src/screen.c.orig	2013-02-25 16:42:10.000000000 +0000
+++ src/screen.c
@@ -252,7 +252,7 @@ show_headers()
 	return(TRUE);
 }
 
-show_current()
+void show_current(void)
 {
 	/** Show the new header, with all the usual checks **/
 
