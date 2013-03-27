$NetBSD$

--- quanta/treeviews/projecttreeview.h.orig	2013-03-26 21:15:58.000000000 +0000
+++ quanta/treeviews/projecttreeview.h
@@ -22,7 +22,9 @@
 #include "basetreeview.h"
 //#include "projecturl.h"
 
-class KIO::Job;
+namespace KIO {
+    class Job;
+}
 class FileInfoDlg;
 class ProjectList;
 
