$NetBSD$

--- core/libs/widgets/common/dfontselect.cpp.orig	2013-02-28 09:42:02.000000000 +0000
+++ core/libs/widgets/common/dfontselect.cpp
@@ -64,7 +64,7 @@ public:
     DFontSelect::FontMode mode;
 };
 
-DFontSelect::DFontSelect(const QString& text=QString(), QWidget* parent=0)
+DFontSelect::DFontSelect(const QString& text, QWidget* parent)
     : KHBox(parent), d(new DFontSelectPriv)
 {
     d->label     = new QLabel(this);
