$NetBSD$

--- gcc/gcov.c.orig	Wed Jan 11 18:58:30 2012
+++ gcc/gcov.c
@@ -64,6 +64,10 @@ along with Gcov; see the file COPYING3.  If not see
 
 /* This is the size of the buffer used to read in source file lines.  */
 
+#ifdef _MINIX
+#define block_t gcc_block_t
+#endif
+
 struct function_info;
 struct block_info;
 struct source_info;
