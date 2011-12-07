$NetBSD$

--- atf-c/detail/process_test.c.orig	Sun Aug 21 01:01:24 2011
+++ atf-c/detail/process_test.c
@@ -28,8 +28,8 @@
  */
 
 #include <sys/types.h>
-#include <sys/resource.h>
 #include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/wait.h>
 
 #include <errno.h>
