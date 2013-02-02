$NetBSD$

--- libxorp/safe_callback_obj.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/safe_callback_obj.hh
@@ -26,7 +26,7 @@
 #include <algorithm>
 #include <vector>
 
-struct SafeCallbackBase;
+class SafeCallbackBase;
 
 /**
  * @short Base class for objects that are callback safe.
