$NetBSD$

For LC_ALL.

--- src/main.c.orig	2012-01-05 20:28:21.000000000 +0000
+++ src/main.c
@@ -26,6 +26,7 @@
 #include <gtk/gtk.h>
 #include <glade/glade.h>
 #include <libintl.h>
+#include <locale.h>
 
 #ifdef G_OS_WIN32
 #include <windows.h>
