$NetBSD$

--- src/Plugins/GenerateGraph/generategraphwidget.h.orig	2012-01-02 19:52:41.000000000 +0000
+++ src/Plugins/GenerateGraph/generategraphwidget.h
@@ -22,8 +22,10 @@
 #include <QWidget>
 #include <KDialog>
 
+#ifndef Q_MOC_RUN
 #include <boost/graph/adjacency_list.hpp>
 #include <boost/graph/topology.hpp>
+#endif
 
 class QGridLayout;
 class Document;
