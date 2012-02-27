$NetBSD$

--- openscad.pro.orig	2011-12-29 17:10:30.000000000 +0000
+++ openscad.pro
@@ -275,6 +275,9 @@ macx {
 
 isEmpty(PREFIX):PREFIX = /usr/local
 
+# fix pkgsrc prefix since it doesn't seem to get it from the environment
+PREFIX = @DESTDIR@@PREFIX@
+
 target.path = $$PREFIX/bin/
 INSTALLS += target
 
