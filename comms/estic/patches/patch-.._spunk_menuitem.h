$NetBSD$

--- ../spunk/menuitem.h.orig	1996-12-10 14:41:04.000000000 +0100
+++ ../spunk/menuitem.h	2012-01-25 18:39:54.872853784 +0100
@@ -27,7 +27,7 @@
 #include "datetime.h"
 #include "charset.h"
 
-
+#undef CS
 
 /*****************************************************************************/
 /*                              class MenueLine                              */
