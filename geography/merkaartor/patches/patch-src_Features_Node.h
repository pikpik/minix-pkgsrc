$NetBSD$

--- src/Features/Node.h.orig	2013-02-25 22:41:59.000000000 +0000
+++ src/Features/Node.h
@@ -12,7 +12,7 @@
 #include <QtCore/QDateTime>
 #include <QtXml>
 
-#ifndef _MOBILE
+#if !defined(_MOBILE) && !defined(Q_MOC_RUN)
 #include <ggl/ggl.hpp>
 #include <ggl/geometries/register/point.hpp>
 #endif
