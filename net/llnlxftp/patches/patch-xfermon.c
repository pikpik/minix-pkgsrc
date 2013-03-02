$NetBSD$

--- xfermon.c.orig	2013-03-01 14:11:21.000000000 +0000
+++ xfermon.c
@@ -59,6 +59,8 @@
 #include <Xm/TextF.h>
 #include "xftp.h"
 
+void create_xfermon_dialog(void);
+
 static struct {
 	Widget w_dialog;
 	Widget w_controlArea;
@@ -109,7 +111,7 @@ show_xfermon()
 /*
  * create_xfermon_dialog - Create file transfer monitor.
  */
-create_xfermon_dialog()
+void create_xfermon_dialog(void)
 {
 	static int initialized = False;
 	XmString label;
