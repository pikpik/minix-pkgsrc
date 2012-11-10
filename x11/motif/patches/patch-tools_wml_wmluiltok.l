$NetBSD$

--- tools/wml/wmluiltok.l.orig	2012-10-22 14:50:39.000000000 +0000
+++ tools/wml/wmluiltok.l
@@ -55,6 +55,8 @@
 
 %a 9999						/* transitions */
 
+%option main
+
 %{
 
 #include <stdio.h>
