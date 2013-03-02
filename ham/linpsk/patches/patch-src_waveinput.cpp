$NetBSD$

--- src/waveinput.cpp.orig	2013-02-28 22:14:51.000000000 +0000
+++ src/waveinput.cpp
@@ -19,7 +19,7 @@
 
 extern Parameter settings;
 
-WaveInput::WaveInput(int ptt = -1): Input(ptt)
+WaveInput::WaveInput(int ptt): Input(ptt)
 {
  EightBits=false;
 }
