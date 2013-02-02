$NetBSD$

--- src/include/refcount_ptr.h.orig	2010-02-14 09:33:54.000000000 +0000
+++ src/include/refcount_ptr.h
@@ -28,6 +28,8 @@
  *  SUCH DAMAGE.
  */
 
+#include <stddef.h>
+
 /**
  * \brief Base class for reference countable objects.
  *
