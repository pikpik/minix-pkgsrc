$NetBSD$

--- rtrmgr/op_commands.ll.orig	2012-07-03 16:30:22.000000000 +0000
+++ rtrmgr/op_commands.ll
@@ -22,6 +22,7 @@
 	extern char* opcmdlval;
 	string opcmd_parsebuf;
 %option noyywrap
+%option noinput
 %option nounput
 %option never-interactive
 %x comment
