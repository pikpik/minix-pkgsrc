$NetBSD$

--- policy/test/compilepolicy.l.orig	2012-07-03 16:32:36.000000000 +0000
+++ policy/test/compilepolicy.l
@@ -26,6 +26,7 @@ namespace {
 %option prefix="yy_compile_policy"
 %option outfile="lex.yy_compile_policy.cc"
 %option noyywrap
+%option noinput
 %option nounput
 %option never-interactive
 %x STR BLOCK
