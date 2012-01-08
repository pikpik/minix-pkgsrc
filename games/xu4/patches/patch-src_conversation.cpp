$NetBSD$

Add missing header.

--- src/conversation.cpp.orig	2005-09-21 06:39:59.000000000 +0000
+++ src/conversation.cpp
@@ -8,6 +8,7 @@
 #include "debug.h"
 #include "person.h"
 #include "script.h"
+#include <string.h>
 
 /* Static variable initialization */
 const unsigned int Conversation::BUFFERLEN = 16;
