$NetBSD$

--- plugins/ADM_audioDevices/Sdl/ADM_deviceSDL.cpp.orig	2008-07-03 19:29:34.000000000 +0000
+++ plugins/ADM_audioDevices/Sdl/ADM_deviceSDL.cpp
@@ -12,7 +12,7 @@
 
 
 #include "ADM_default.h"
-#include "SDL.h"
+#include <SDL/SDL.h>
 
 #include  "ADM_audiodevice.h"
 #include  "ADM_audioDeviceInternal.h"
