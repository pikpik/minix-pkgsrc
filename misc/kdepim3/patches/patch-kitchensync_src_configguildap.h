$NetBSD$

--- kitchensync/src/configguildap.h.orig	2013-03-26 09:28:47.000000000 +0000
+++ kitchensync/src/configguildap.h
@@ -29,7 +29,9 @@ class QCheckBox;
 class QLabel;
 class QSpinBox;
 
-class KABC::LdapConfigWidget;
+namespace KABC {
+class LdapConfigWidget;
+}
 class KComboBox;
 class KLineEdit;
 
