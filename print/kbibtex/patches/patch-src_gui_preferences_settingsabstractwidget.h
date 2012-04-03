$NetBSD$

fix build from 0.4 branch

--- src/gui/preferences/settingsabstractwidget.h.orig	2011-11-20 20:36:54.000000000 +0000
+++ src/gui/preferences/settingsabstractwidget.h
@@ -24,6 +24,7 @@
 #include <kbibtexgui_export.h>
 
 #include <QWidget>
+#include <QAbstractItemModel>
 
 class KComboBox;
 
