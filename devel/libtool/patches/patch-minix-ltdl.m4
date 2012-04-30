$NetBSD$

--- libltdl/m4/ltdl.m4.orig	Thu Apr 26 22:41:58 2012
+++ libltdl/m4/ltdl.m4
@@ -490,6 +490,9 @@ AC_CACHE_CHECK([whether deplibs are loaded by dlopen],
   netbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
+  minix*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;; 
   openbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
