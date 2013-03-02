$NetBSD$

--- src/textinput.cpp.orig	2013-02-28 22:14:28.000000000 +0000
+++ src/textinput.cpp
@@ -22,7 +22,7 @@
 extern Parameter settings;
 extern int errno;
 
-TextInput::TextInput(int ptt = -1):Input(ptt)
+TextInput::TextInput(int ptt):Input(ptt)
 {
 }
 TextInput::~TextInput()
