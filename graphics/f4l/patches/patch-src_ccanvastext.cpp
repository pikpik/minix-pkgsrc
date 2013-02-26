$NetBSD$

--- src/ccanvastext.cpp.orig	2013-02-25 16:57:44.000000000 +0000
+++ src/ccanvastext.cpp
@@ -19,7 +19,7 @@
  ***************************************************************************/
 #include "ccanvastext.h"
 
-CCanvasText::CCanvasText( const QString & t="",QCanvas * canvas=0)
+CCanvasText::CCanvasText( const QString & t,QCanvas * canvas)
  : QCanvasText(t,canvas)
 {
 }
