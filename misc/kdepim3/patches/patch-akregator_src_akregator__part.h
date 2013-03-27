$NetBSD$

--- akregator/src/akregator_part.h.orig	2013-03-26 09:33:46.000000000 +0000
+++ akregator/src/akregator_part.h
@@ -40,7 +40,10 @@ class QTimer;
 class KAboutData;
 class KConfig;
 class KURL;
-class KParts::BrowserExtension;
+
+namespace KParts {
+    class BrowserExtension;
+}
 
 namespace Akregator
 {
