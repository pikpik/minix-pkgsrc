$NetBSD$

--- src/conf_lex.l.orig	2000-01-27 14:42:24.000000000 +0000
+++ src/conf_lex.l
@@ -12,7 +12,7 @@ EX      [" "\t]*
 
 %{
 
-#define YYDEBUG
+#define YYDEBUG 1
 
 #include <string.h>
 #include "conf_yacc.h"
