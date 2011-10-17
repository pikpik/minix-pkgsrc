$NetBSD$

--- include/cppunit/portability/FloatingPoint.h.orig	2007-03-05 04:16:42.000000000 +0100
+++ include/cppunit/portability/FloatingPoint.h	2011-09-13 15:48:01.512720874 +0200
@@ -4,6 +4,10 @@
 #include <cppunit/Portability.h>
 #include <math.h>
 
+#ifdef __sun
+#include <ieeefp.h>
+#endif
+
 CPPUNIT_NS_BEGIN
 
 /// \brief Tests if a floating-point is a NaN.
