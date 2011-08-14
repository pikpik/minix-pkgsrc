$NetBSD$

With videoproto-2.3.1 and newer XvMClib.h is nolonger included by
vldXvMC.h.

--- src/video_out/xxmc.h.orig	2011-01-18 00:24:24.000000000 +0000
+++ src/video_out/xxmc.h
@@ -79,6 +79,7 @@
 #include <X11/extensions/Xvlib.h>
 #ifdef HAVE_VLDXVMC
   #include <X11/extensions/vldXvMC.h>
+  #include <X11/extensions/XvMClib.h>
 #else
   #include <X11/extensions/XvMClib.h>
   #include <X11/extensions/XvMC.h>
