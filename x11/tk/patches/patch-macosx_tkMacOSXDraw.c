$NetBSD$

Void function should not return any values.

--- macosx/tkMacOSXDraw.c.orig	2012-11-24 20:55:20.000000000 +0000
+++ macosx/tkMacOSXDraw.c
@@ -744,7 +744,7 @@ DrawCGImage(
     } else {
 	TkMacOSXDbgMsg("Drawing of empty CGImage requested");
     }
-    return Success;
+    return;
 }
 
 /*
