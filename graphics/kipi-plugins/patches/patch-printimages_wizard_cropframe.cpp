$NetBSD$

--- printimages/wizard/cropframe.cpp.orig	2013-02-28 12:07:37.000000000 +0000
+++ printimages/wizard/cropframe.cpp
@@ -41,7 +41,7 @@
 namespace KIPIPrintImagesPlugin
 {
 
-CropFrame::CropFrame(QWidget* parent=0)
+CropFrame::CropFrame(QWidget* parent)
     : QWidget(parent)
 {
     m_mouseDown = false;
