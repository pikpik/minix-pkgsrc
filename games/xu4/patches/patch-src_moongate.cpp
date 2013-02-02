$NetBSD$

Provide NULL if it's missing. Apparently Required on Dragonfly.

--- src/moongate.cpp~	2004-06-01 15:07:45.000000000 +0000
+++ src/moongate.cpp
@@ -11,6 +11,10 @@
 #include "moongate.h"
 #include "types.h"
 
+#ifndef NULL
+#define NULL 0
+#endif
+
 typedef std::map<int, Coords> MoongateList; /* map moon phase to map coordinates */
 
 MoongateList gates; 
