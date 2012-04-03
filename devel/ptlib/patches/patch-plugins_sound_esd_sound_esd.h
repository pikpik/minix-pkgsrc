$NetBSD$

--- plugins/sound_esd/sound_esd.h.orig	2009-09-21 00:25:31.000000000 +0000
+++ plugins/sound_esd/sound_esd.h
@@ -11,6 +11,10 @@
 #include <sys/soundcard.h>
 #endif
 
+#ifdef P_DRAGONFLY
+#include <sys/soundcard.h>
+#endif
+
 #ifdef P_FREEBSD
 #if P_FREEBSD >= 500000
 #include <sys/soundcard.h>
