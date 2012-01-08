$NetBSD$

Add missing header.

--- src/dialogueloader.cpp.orig	2005-01-21 08:02:52.000000000 +0000
+++ src/dialogueloader.cpp
@@ -7,6 +7,7 @@
 #include "debug.h"
 #include "conversation.h"
 #include "dialogueloader.h"
+#include <stdlib.h>
 
 std::map<std::string, DialogueLoader *> *DialogueLoader::loaderMap = NULL;
 
