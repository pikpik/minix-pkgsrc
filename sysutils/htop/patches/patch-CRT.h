$NetBSD$

--- CRT.h.orig	2010-11-23 15:56:32.000000000 +0000
+++ CRT.h
@@ -14,7 +14,9 @@ in the source distribution for its full 
 #include <signal.h>
 #include <stdlib.h>
 #include <stdbool.h>
+#ifdef HAVE_EXECINFO_H
 #include <execinfo.h>
+#endif
 
 #include "String.h"
 
