$NetBSD$

--- compress/misc.c.orig	2012-11-18 22:59:30.000000000 +0000
+++ compress/misc.c
@@ -288,6 +288,7 @@ int	flags;
 	return 1;
 }
 
+void
 uninitialize_common()
 {
 	initialize_common_done = 0;
