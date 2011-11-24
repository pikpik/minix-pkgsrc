$NetBSD$

--- src/kpart/TopicTree.cpp.orig	2011-11-24 01:26:22.000000000 +0000
+++ src/kpart/TopicTree.cpp
@@ -22,6 +22,7 @@
 #include <qtimer.h>
 #include <qregexp.h>
 #include <qtextcodec.h>
+#include <memory>
 
 #include "TopicTree.h"
 #include "TopicLeaf.h"
