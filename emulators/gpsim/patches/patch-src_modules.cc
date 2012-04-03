$NetBSD$

Add missing include.

--- src/modules.cc.orig	2005-09-16 13:58:24.000000000 +0000
+++ src/modules.cc
@@ -28,6 +28,7 @@ Boston, MA 02111-1307, USA.  */
 #include <string>
 #include <list>
 #include <vector>
+#include <typeinfo>
 
 #include "../config.h"
 
