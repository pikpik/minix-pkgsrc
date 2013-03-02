$NetBSD$

--- core/libs/template/templateviewer.cpp.orig	2013-02-28 10:07:32.000000000 +0000
+++ core/libs/template/templateviewer.cpp
@@ -152,7 +152,7 @@ public:
     DTextList*      subjectsList;
 };
 
-TemplateViewer::TemplateViewer(QWidget* parent=0)
+TemplateViewer::TemplateViewer(QWidget* parent)
     : RExpanderBox(parent), d(new TemplateViewerPriv)
 {
     setFrameStyle(QFrame::NoFrame);
