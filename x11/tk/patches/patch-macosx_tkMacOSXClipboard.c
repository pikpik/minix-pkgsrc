$NetBSD$

Void function should not return any values.

--- macosx/tkMacOSXClipboard.c.orig	2012-11-24 20:54:23.000000000 +0000
+++ macosx/tkMacOSXClipboard.c
@@ -194,7 +194,7 @@ TkMacOSXSelDeadWindow(
     if (winPtr && winPtr == (TkWindow *)clipboardOwner) {
 	clipboardOwner = NULL;
     }
-    return Success;
+    return;
 }
 
 /*
