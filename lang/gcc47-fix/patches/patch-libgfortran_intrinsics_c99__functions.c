$NetBSD$

--- libgfortran/intrinsics/c99_functions.c.orig	Tue Nov  8 10:31:04 2011
+++ libgfortran/intrinsics/c99_functions.c
@@ -1805,7 +1805,7 @@ catanhl (complex long double z)
 #endif
 
 
-#if !defined(HAVE_TGAMMA)
+#if !defined(HAVE_TGAMMA) && defined(HAVE_NEXTAFTER)
 #define HAVE_TGAMMA 1
 double tgamma (double); 
 
@@ -1943,7 +1943,7 @@ tgamma (double x)
 
 
 
-#if !defined(HAVE_LGAMMA)
+#if !defined(HAVE_LGAMMA) && defined(HAVE_NEXTAFTER)
 #define HAVE_LGAMMA 1
 double lgamma (double); 
 
