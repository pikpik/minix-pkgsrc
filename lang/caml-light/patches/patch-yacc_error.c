$NetBSD$

--- yacc/error.c.orig	2012-10-20 13:06:22.000000000 +0000
+++ yacc/error.c
@@ -34,7 +34,7 @@ unexpected_EOF()
 }
 
 
-print_pos(st_line, st_cptr)
+void print_pos(st_line, st_cptr)
 char *st_line;
 char *st_cptr;
 {
