$NetBSD$

--- src/db_lex.l.orig	1999-11-25 14:22:50.000000000 +0000
+++ src/db_lex.l
@@ -24,7 +24,7 @@ extern YYSTYPE yylval;
 #define YY_DECL int db_scan(void)
 
 
-#define YYDEBUG
+#define YYDEBUG 1
 
 #include "conf_yacc.h"
 #include <string.h>
