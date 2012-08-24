$NetBSD$

--- libgcc/libgcov.c.orig	Wed Jan 11 18:50:21 2012
+++ libgcc/libgcov.c
@@ -41,6 +41,11 @@ see the files COPYING3 and COPYING.RUNTIME respectivel
 #define GCOV_LINKAGE /* nothing */
 #endif
 #endif
+
+#ifndef L_gcov_merge_add
+#include "gcov-minix-fs-wrapper.h"
+#endif
+
 #include "gcov-io.h"
 
 #if defined(inhibit_libc)
@@ -269,7 +274,7 @@ gcov_version (struct gcov_info *ptr, gcov_unsigned_t v
    in two separate programs, and we must keep the two program
    summaries separate.  */
 
-static void
+void
 gcov_exit (void)
 {
   struct gcov_info *gi_ptr;
@@ -696,9 +701,13 @@ __gcov_init (struct gcov_info *info)
       if (filename_length > gcov_max_filename)
         gcov_max_filename = filename_length;
 
-      if (!gcov_list)
-	atexit (gcov_exit);
-
+      if (!gcov_list) {
+#ifdef _MINIX
+          atexit (gcov_exit_wrapper);
+#else
+          atexit (gcov_exit);
+#endif
+      }
       info->next = gcov_list;
       gcov_list = info;
     }
