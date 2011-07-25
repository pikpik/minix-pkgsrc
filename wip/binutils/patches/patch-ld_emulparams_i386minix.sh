$NetBSD$

--- ld/emulparams/i386minix.sh.orig	Mon Jul 25 16:24:38 2011
+++ ld/emulparams/i386minix.sh
@@ -0,0 +1,6 @@
+SCRIPT_NAME=aout
+OUTPUT_FORMAT="a.out-i386-minix"
+TARGET_PAGE_SIZE=1
+TEXT_START_ADDR=0
+NONPAGED_TEXT_START_ADDR=0
+ARCH=i386
