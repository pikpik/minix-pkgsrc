$NetBSD$

--- src/wdiff.c.orig	Sat Dec  4 16:16:13 2010
+++ src/wdiff.c
@@ -70,6 +70,9 @@
 # define RETSIGTYPE void
 #endif
 
+/* Needed for S_IFDIR */
+#define _XOPEN_SOURCE
+
 #include <sys/stat.h>
 #include <unistd.h>
 #include <getopt.h>
