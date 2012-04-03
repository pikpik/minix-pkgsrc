$NetBSD$

--- agent/edusers.SH.orig	2001-03-17 18:31:17.000000000 +0000
+++ agent/edusers.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/edusers (with var
 $spitshell >edusers <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
