$NetBSD$

--- krusader/VFS/temp_vfs.h.orig	2012-12-22 01:45:21.000000000 +0000
+++ krusader/VFS/temp_vfs.h
@@ -52,6 +52,8 @@ protected:
 	void handleIso(QString origin);
   QString tmpDir;
 
+private:
+	QString type;
 };
 
 #endif
