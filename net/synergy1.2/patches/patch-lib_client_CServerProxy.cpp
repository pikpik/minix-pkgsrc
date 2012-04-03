$NetBSD$

--- lib/client/CServerProxy.cpp.orig	2011-11-22 19:39:17.000000000 +0000
+++ lib/client/CServerProxy.cpp
@@ -24,6 +24,7 @@
 #include "TMethodEventJob.h"
 #include "XBase.h"
 #include <memory>
+#include <string.h>
 
 //
 // CServerProxy
