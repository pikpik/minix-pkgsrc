$NetBSD: patch-gui-gui_watch.cc,v 1.1 2011/09/08 00:12:00 joerg Exp $

--- gui/gui_watch.cc.orig	2005-08-31 14:46:39.000000000 +0000
+++ gui/gui_watch.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <typeinfo>
 
 #include "../config.h"
 #ifdef HAVE_GUI
@@ -478,7 +479,7 @@ void Watch_Window::UpdateWatch(WatchEntr
     strcpy(str, "?");
   }
   else {
-    sprintf(str,"%d", rvNewValue);
+    sprintf(str,"%d", new_value);
   }
   gtk_clist_set_text(GTK_CLIST(watch_clist), row, DECIMALCOL, str);
 
