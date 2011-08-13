--- libgcc/libgcov.c.orig	Fri May 13 15:57:20 2011
+++ libgcc/libgcov.c	Thu Aug  4 19:23:46 2011
@@ -40,6 +40,11 @@ see the files COPYING3 and COPYING.RUNTIME respectivel
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
@@ -165,7 +170,7 @@ gcov_version (struct gcov_info *ptr, gcov_unsigned_t v
    in two separate programs, and we must keep the two program
    summaries separate.  */
 
-static void
+void
 gcov_exit (void)
 {
   struct gcov_info *gi_ptr;
@@ -596,8 +601,13 @@ __gcov_init (struct gcov_info *info)
 
       gcov_crc32 = crc32;
 
-      if (!gcov_list)
+      if (!gcov_list) {
+#ifdef _MINIX
+       atexit (gcov_exit_wrapper);
+#else
 	atexit (gcov_exit);
+#endif
+      }
 
       info->next = gcov_list;
       gcov_list = info;
