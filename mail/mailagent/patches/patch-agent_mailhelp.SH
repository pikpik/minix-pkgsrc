$NetBSD$

--- agent/mailhelp.SH.orig	2001-03-17 18:31:22.000000000 +0000
+++ agent/mailhelp.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/mailhelp (with va
 $spitshell >mailhelp <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
