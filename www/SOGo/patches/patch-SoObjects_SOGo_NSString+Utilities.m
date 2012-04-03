$NetBSD$

--- SoObjects/SOGo/NSString+Utilities.m.orig	2011-12-05 18:16:46.000000000 +0000
+++ SoObjects/SOGo/NSString+Utilities.m
@@ -21,7 +21,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#ifndef __OpenBSD__ 
+#ifdef __sun
 #include <crypt.h>
 #endif
 
