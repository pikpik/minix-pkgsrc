$NetBSD$

--- intern/elbeem/intern/ntl_vector3dim.h.orig	2012-07-03 13:12:36.000000000 +0000
+++ intern/elbeem/intern/ntl_vector3dim.h
@@ -24,6 +24,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+/* absolute value */
+template < class T >
+inline T
+ABS( T a )
+{ return (0 < a) ? a : -a ; }
+
 // hack for MSVC6.0 compiler
 #ifdef _MSC_VER
 #if _MSC_VER < 1300
