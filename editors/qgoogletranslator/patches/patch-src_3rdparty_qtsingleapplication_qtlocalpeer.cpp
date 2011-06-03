$NetBSD$

--- src/3rdparty/qtsingleapplication/qtlocalpeer.cpp.orig	2010-11-16 20:24:09.000000000 +0000
+++ src/3rdparty/qtsingleapplication/qtlocalpeer.cpp
@@ -45,6 +45,7 @@
 ****************************************************************************/
 
 
+#include "errno.h"
 #include "qtlocalpeer.h"
 #include <QtCore/QCoreApplication>
 #include <QtCore/QTime>
