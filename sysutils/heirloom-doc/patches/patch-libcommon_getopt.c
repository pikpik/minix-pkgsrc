$NetBSD$

--- libcommon/getopt.c.orig	Mon Apr  2 14:45:48 2007
+++ libcommon/getopt.c
@@ -7,7 +7,11 @@
 /*	Sccsid @(#)getopt.c	1.5 (gritter) 4/2/07	*/
 
 #include	<sys/types.h>
+#ifdef __minix
+#include <stdlib.h>
+#else
 #include	<alloca.h>
+#endif
 #include	<string.h>
 #include	"msgselect.h"
 
