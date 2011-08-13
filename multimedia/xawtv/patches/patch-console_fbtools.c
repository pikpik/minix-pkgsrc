$NetBSD$

--- console/fbtools.c.orig	2003-02-14 14:14:04.000000000 +0000
+++ console/fbtools.c
@@ -21,7 +21,7 @@
 #include <linux/vt.h>
 #include <linux/fb.h>
 
-#include <asm/page.h>
+#include <sys/user.h>
 
 #include "fbtools.h"
 
