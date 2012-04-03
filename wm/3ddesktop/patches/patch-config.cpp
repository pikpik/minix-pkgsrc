$NetBSD$

--- config.cpp.orig	2011-11-25 13:25:07.000000000 +0000
+++ config.cpp
@@ -19,6 +19,7 @@
 //  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 //
 
+#include <string.h>
 #include "config.hpp"
 
 static void 
