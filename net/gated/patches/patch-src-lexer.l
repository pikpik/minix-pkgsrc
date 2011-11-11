$NetBSD$

--- src/lexer.l.orig	1998-09-15 16:46:49.000000000 +0000
+++ src/lexer.l
@@ -176,8 +176,6 @@ PROTOTYPE(parse_eof,
 
 #define	YYTEXT	yytext
 
-int yylineno = 0;
-
 #undef	YY_INPUT
 #define	YY_INPUT(buf, result, max_size) \
 { \
