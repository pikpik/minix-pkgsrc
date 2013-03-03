$NetBSD$

--- windows/windows.h.orig	2013-03-02 22:33:29.000000000 +0000
+++ windows/windows.h
@@ -246,7 +246,7 @@ extern int WindExecute();
 extern void WindAddCommand();
 extern int WindReplaceCommand();
 extern char **WindGetCommandTable();
-extern int windCheckOnlyWindow(MagWindow **, WindClient);
+extern void windCheckOnlyWindow(MagWindow **, WindClient);
 
 
 /* searching procs */
$NetBSD$

--- windows/windows.h.orig	2013-03-02 22:33:29.000000000 +0000
+++ windows/windows.h
@@ -246,7 +246,7 @@ extern int WindExecute();
 extern void WindAddCommand();
 extern int WindReplaceCommand();
 extern char **WindGetCommandTable();
-extern int windCheckOnlyWindow(MagWindow **, WindClient);
+extern void windCheckOnlyWindow(MagWindow **, WindClient);
 
 
 /* searching procs */
