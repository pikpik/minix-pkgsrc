--- gcc/gcov.c.orig	Mon May 23 10:20:01 2011
+++ gcc/gcov.c	Thu Aug  4 19:02:37 2011
--- gcc/gcov.c.orig	Mon May 23 10:20:01 2011
+++ gcc/gcov.c
@@ -66,6 +66,10 @@ along with Gcov; see the file COPYING3.  If not see
 
 #define STRING_SIZE 200
 
+#ifdef _MINIX
+#define block_t gcc_block_t
+#endif
+
 struct function_info;
 struct block_info;
 struct source_info;
