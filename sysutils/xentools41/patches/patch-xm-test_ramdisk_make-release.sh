$NetBSD$

--- xm-test/ramdisk/make-release.sh.orig	2011-03-25 10:42:56.000000000 +0000
+++ xm-test/ramdisk/make-release.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-if [ "$1" == "" ]
+if [ "$1" = "" ]
 then
   arch=""
 else
