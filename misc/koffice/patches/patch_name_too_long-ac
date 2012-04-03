$NetBSD$

--- krita/plugins/filters/levelfilter/kis_level_filter.cc.orig	2011-12-05 18:43:45.000000000 +0000
+++ krita/plugins/filters/levelfilter/kis_level_filter.cc
@@ -277,7 +277,7 @@ void KisLevelConfigWidget::drawHistogram
     QPixmap pix(256, height);
     pix.fill();
     QPainter p(&pix);
-    p.setPen(QPen::QPen(Qt::gray,1, Qt::SolidLine));
+    p.setPen(QPen(Qt::gray,1, Qt::SolidLine));
 
     double highest = (double)histogram->calculations().getHighest();
     Q_INT32 bins = histogram->producer()->numberOfBins();
