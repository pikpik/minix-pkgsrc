$NetBSD$

--- js/src/yarr/pcre/pcre.h.orig	2012-01-29 11:24:38.000000000 +0100
+++ js/src/yarr/pcre/pcre.h	2012-02-20 16:50:06.000000000 +0100
@@ -46,7 +46,9 @@
 #include "assembler/wtf/Platform.h"
 #include "jsstr.h"
 #include "jsprvtd.h"
+#if ENABLE_ASSEMBLER
 #include "jstl.h"
+#endif
 
 typedef jschar UChar;
 typedef JSLinearString UString;
