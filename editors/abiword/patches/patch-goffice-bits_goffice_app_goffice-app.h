$NetBSD$

Fix build with glib-2.32.

--- goffice-bits/goffice/app/goffice-app.h.orig	2007-01-16 23:17:27.000000000 +0000
+++ goffice-bits/goffice/app/goffice-app.h
@@ -22,7 +22,7 @@
 #ifndef GOFFICE_APP_H
 #define GOFFICE_APP_H
 
-#include <glib/gmacros.h>
+#include <glib.h>
 
 G_BEGIN_DECLS
 
