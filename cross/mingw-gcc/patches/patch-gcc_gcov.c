--- gcc/gcov.c.orig	Wed Feb  6 13:07:54 2013
+++ gcc/gcov.c	Wed Feb  6 13:08:08 2013
@@ -68,6 +68,10 @@
 
 #define STRING_SIZE 200
 
+#ifdef __minix
+#define block_t gcc_block_t
+#endif
+
 struct function_info;
 struct block_info;
 struct source_info;
