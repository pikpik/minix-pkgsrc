$NetBSD$

--- agent/maillist.SH.orig	2001-03-17 18:31:22.000000000 +0000
+++ agent/maillist.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/maillist (with va
 $spitshell >maillist <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
