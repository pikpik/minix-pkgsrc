$NetBSD$

--- test/Unit/endianness.h.orig	Thu Nov 24 17:14:43 2011
+++ test/Unit/endianness.h
@@ -85,6 +85,19 @@
 
 #endif /* GNU/Linux */
 
+#if defined(__minix)
+#include <net/hton.h>
+#if BIG_ENDIAN
+#define _YUGA_LITTLE_ENDIAN    0
+#define _YUGA_BIG_ENDIAN       1
+#elif LITTLE_ENDIAN
+#define _YUGA_LITTLE_ENDIAN    1
+#define _YUGA_BIG_ENDIAN       0
+#else
+#error No Minix endianness found
+#endif
+#endif
+
 /* . */
 
 #if !defined(_YUGA_LITTLE_ENDIAN) || !defined(_YUGA_BIG_ENDIAN)
