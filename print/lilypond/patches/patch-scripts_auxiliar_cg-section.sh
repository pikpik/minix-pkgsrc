$NetBSD$

Fix unportable test(1) construct.

--- scripts/auxiliar/cg-section.sh.orig	2013-01-04 13:41:56.000000000 +0000
+++ scripts/auxiliar/cg-section.sh
@@ -31,7 +31,7 @@ EOF
     exit "$1"
 }
 
-if [ "$1" == '-h' ] || [ "$1" == '--help' ]; then
+if [ "$1" = '-h' ] || [ "$1" = '--help' ]; then
     usage 0
 fi
 
