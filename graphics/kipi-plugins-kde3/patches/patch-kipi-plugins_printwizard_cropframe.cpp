$NetBSD$

--- kipi-plugins/printwizard/cropframe.cpp.orig	2013-02-25 15:12:43.000000000 +0000
+++ kipi-plugins/printwizard/cropframe.cpp
@@ -36,7 +36,7 @@ extern "C"
 namespace KIPIPrintWizardPlugin
 {
 
-CropFrame::CropFrame(QWidget *parent=0, const char *name=0)
+CropFrame::CropFrame(QWidget *parent, const char *name)
          : QWidget(parent, name)
 {
   m_mouseDown = false;
