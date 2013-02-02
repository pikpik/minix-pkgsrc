$NetBSD$

Fix "error: reclaration of `int c`" on gcc 4.7.

--- FeLib/Source/bitmap.cpp.orig	2004-10-26 19:35:47.000000000 +0000
+++ FeLib/Source/bitmap.cpp
@@ -881,7 +881,7 @@ void bitmap::DrawLine(int OrigFromX, int
     const int Y2 = OrigToY + PointY[c];
     const int DeltaX = abs(X2 - X1);
     const int DeltaY = abs(Y2 - Y1);
-    int x, c;
+    int x;
     int XChange, PtrXChange, PtrYChange;
     int DoubleDeltaX, DoubleDeltaY, End;
 
