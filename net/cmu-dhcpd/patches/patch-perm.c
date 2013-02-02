$NetBSD$

--- perm.c.orig	2012-11-21 16:06:25.000000000 +0000
+++ perm.c
@@ -273,7 +273,7 @@ void	flush_disk()
 }
 
 
-int release_lastbind(hp)
+void release_lastbind(hp)
 struct host *hp;
 {
 	struct lastbind *b,t;
