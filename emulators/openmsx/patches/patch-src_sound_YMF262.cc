$NetBSD$

--- src/sound/YMF262.cc.orig	2011-11-24 02:46:36.000000000 +0000
+++ src/sound/YMF262.cc
@@ -43,6 +43,7 @@
 #include "SimpleDebuggable.hh"
 #include "MSXMotherBoard.hh"
 #include <cmath>
+#include <cstring>
 
 namespace openmsx {
 
