$NetBSD$

--- rtrmgr/template.ll.orig	2012-07-03 16:28:04.000000000 +0000
+++ rtrmgr/template.ll
@@ -21,6 +21,7 @@
 	extern char* tpltlval;
 	string tplt_parsebuf;
 %option noyywrap
+%option noinput
 %option nounput
 %option never-interactive
 %x comment
