$NetBSD$

--- src/Features/Way.h.orig	2013-02-25 22:42:09.000000000 +0000
+++ src/Features/Way.h
@@ -8,7 +8,7 @@
 #include "Layer.h"
 #include "OsbLayer.h"
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 #include <ggl/ggl.hpp>
 #endif
 
