$NetBSD$

--- header_f.h.orig	2013-01-10 23:04:10.000000000 +0000
+++ header_f.h
@@ -61,5 +61,5 @@ void new_transaction(char *message);
 
 void print_message_line(char *message);
 
-inline char* get_body(char *mes);
+char* get_body(char *mes);
 #endif
