$NetBSD$

--- console/matrox.c.orig	2005-02-03 10:40:41.000000000 +0000
+++ console/matrox.c
@@ -9,7 +9,7 @@
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 
-#include <asm/page.h> /* PAGE_SIZE */
+#include <sys/user.h> /* PAGE_SIZE */
 #include <linux/fb.h>
 
 #include "byteswap.h"
