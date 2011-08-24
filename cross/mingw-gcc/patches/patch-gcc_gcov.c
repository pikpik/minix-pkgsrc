--- gcc/gcov.c.orig	Fri Feb 20 06:47:11 2004
+++ gcc/gcov.c	Wed Aug 24 00:32:38 2011
@@ -68,6 +68,10 @@
 
 #define STRING_SIZE 200
 
+#ifdef _MINIX
+#define block_t gcc_block_t
+#endif
+
 struct function_info;
 struct block_info;
 struct source_info;
