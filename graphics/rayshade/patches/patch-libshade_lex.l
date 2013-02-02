$NetBSD$

--- libshade/lex.l.orig	1992-02-10 03:04:02.000000000 +0000
+++ libshade/lex.l
@@ -28,7 +28,10 @@
 #include "symtab.h"
 #include "y.tab.h"
 extern char *strsave();
+static void skipcomments(void);
+
 %}
+%option yylineno
 alpha	[a-zA-Z]
 special	[\.\_-]
 digit	[0-9]
@@ -163,7 +166,7 @@ yywrap() {return 1;}
 /*
  * Skip over comments.
  */
-skipcomments()
+static void skipcomments(void)
 {
 	char c;
 
