$NetBSD$

--- src/fractionbasewidget.cpp.orig	2013-01-14 22:51:55.000000000 +0000
+++ src/fractionbasewidget.cpp
@@ -30,7 +30,7 @@
 
 #include "settingsclass.h"
 
-FractionBaseWidget::FractionBaseWidget(QWidget * parent = 0) :
+FractionBaseWidget::FractionBaseWidget(QWidget * parent) :
     QWidget(parent)
 {
 #ifdef DEBUG
