$NetBSD$

--- htmlexport/wizard.cpp.orig	2013-02-28 12:13:45.000000000 +0000
+++ htmlexport/wizard.cpp
@@ -78,7 +78,7 @@ class WizardPage : public QWidget, publi
 public:
     WizardPage(KAssistantDialog* dialog, const QString& title)
     : QWidget(dialog) {
-        setupUi(this);
+        this->setupUi(this);
         layout()->setMargin(0);
         mPage = dialog->addPage(this, title);
     }
