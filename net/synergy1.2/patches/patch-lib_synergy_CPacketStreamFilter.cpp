$NetBSD$

--- lib/synergy/CPacketStreamFilter.cpp.orig	2011-11-22 19:37:00.000000000 +0000
+++ lib/synergy/CPacketStreamFilter.cpp
@@ -16,6 +16,7 @@
 #include "IEventQueue.h"
 #include "CLock.h"
 #include "TMethodEventJob.h"
+#include <string.h>
 
 //
 // CPacketStreamFilter
