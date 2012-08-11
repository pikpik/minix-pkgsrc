$NetBSD$

Add DragonFly support.

--- src/ZipArchive/ZipFile_stl.cpp.orig	2012-02-25 10:54:10.000000000 +0000
+++ src/ZipArchive/ZipFile_stl.cpp
@@ -16,7 +16,7 @@
 
 #if (defined _ZIP_IMPL_STL && (!defined _ZIP_FILE_IMPLEMENTATION || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_DEFAULT)) || _ZIP_FILE_IMPLEMENTATION == ZIP_ZFI_STL
 
-#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ 
+#if defined __APPLE__ || defined __CYGWIN__ || defined __NetBSD__ || defined __DragonFly__
 	#define FILE_FUNCTIONS_64B_BY_DEFAULT
 #else
 	#undef FILE_FUNCTIONS_64B_BY_DEFAULT	
