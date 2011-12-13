$NetBSD$

--- lib/int_endianness.h.orig	Thu Nov 24 17:14:46 2011
+++ lib/int_endianness.h
@@ -80,6 +80,19 @@
 
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
