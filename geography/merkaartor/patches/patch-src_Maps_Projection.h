$NetBSD$

--- src/Maps/Projection.h.orig	2013-02-25 22:35:30.000000000 +0000
+++ src/Maps/Projection.h
@@ -6,7 +6,7 @@
 
 #include <QPointF>
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 
 #include "Preferences/MerkaartorPreferences.h"
 
