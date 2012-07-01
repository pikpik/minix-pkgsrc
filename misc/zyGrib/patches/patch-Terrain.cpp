$NetBSD: patch-Terrain.cpp,v 1.1 2012/06/15 18:56:58 joerg Exp $

--- Terrain.cpp.orig	2012-06-03 21:03:41.000000000 +0000
+++ Terrain.cpp
@@ -1032,7 +1032,7 @@ void Terrain::paintEvent(QPaintEvent * /
             
             if (showOrthodromie)
             {
-                QPen penLine(QColor(Qt::white));
+                QPen penLine = QColor(Qt::white);
                 penLine.setWidthF(1.6);
                 pnt.setPen(penLine);
                 draw_Orthodromie(pnt);
