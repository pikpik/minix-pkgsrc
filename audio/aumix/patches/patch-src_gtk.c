$NetBSD$

--- src/gtk.c.orig	Mon Jun 26 22:51:42 2000
+++ src/gtk.c	Tue Jul 11 10:01:52 2000
@@ -19,13 +19,13 @@
  * February 23rd, 2000
  */
 
-#include "common.h"
+#include "./common.h"
 #ifdef HAVE_GTK
-#include "gtk.h"
+#include "./gtk.h"
 #include "../data/aumix.xpm"
-#include "record.xpm"
-#include "play.xpm"
-#include "interactive.h"
+#include "./record.xpm"
+#include "./play.xpm"
+#include "./interactive.h"
 #include <signal.h>		/* SIGALRM */
 
 void            SaveSettingsGTK(void)
