$NetBSD$

--- src/db_lex.c.orig	1999-11-25 14:44:34.000000000 +0000
+++ src/db_lex.c
@@ -418,7 +418,7 @@ extern YYSTYPE yylval;
 #define YY_DECL int db_scan(void)
 
 
-#define YYDEBUG
+#define YYDEBUG 1
 
 #include "conf_yacc.h"
 #include <string.h>
