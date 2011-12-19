$NetBSD$

--- gui/gui_stack.cc.orig	2005-08-31 14:46:39.000000000 +0000
+++ gui/gui_stack.cc
@@ -21,6 +21,7 @@ Boston, MA 02111-1307, USA.  */
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <typeinfo>
 #include <errno.h>
 
 #include "../config.h"
