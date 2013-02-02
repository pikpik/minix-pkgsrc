$NetBSD$

--- spunk/xsrc/console.cc.orig	1997-02-18 14:32:40.000000000 +0000
+++ spunk/xsrc/console.cc
@@ -1013,7 +1013,7 @@ void ScrSetCursorPos (unsigned X, unsign
 void ScrSetMode (unsigned Mode)
 // Set a screen mode
 {
-    unsigned XSize, YSize;
+    int XSize, YSize;
     _ColorMode NewColorMode = ColorMode;
 
     // Check the new dimensions
