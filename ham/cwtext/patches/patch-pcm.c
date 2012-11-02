$NetBSD$

--- pcm.c.orig	2012-10-30 22:47:38.000000000 +0000
+++ pcm.c
@@ -60,7 +60,7 @@ int mStoSamples(int hVox, int time) {
   float samples;
   float fsr;
   
-  if (!valid(hVox)) return;
+  if (!valid(hVox)) return -1;
 
   timelen = (float) time;
   fsr = (float) voxref(hVox).samplerate;
